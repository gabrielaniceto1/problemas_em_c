// agua.c - Editor Raylib (PT-BR) sem letras, janela grande, "pixels" pequenos e pincel ajustável
// Compilar (Windows MSYS2/MinGW):
//   gcc agua.c -O2 -Wall -o water.exe -lraylib -lopengl32 -lgdi32 -lwinmm
// Linux:
//   gcc agua.c -O2 -Wall -o water -lraylib -lm -lpthread -ldl -lrt -lX11
// macOS (brew):
//   # gcc agua.c -O2 -Wall -o water -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    TILE_VAZIO   = 0,
    TILE_TERRA   = 1,
    TILE_ROCHA   = 2,
    TILE_FONTE   = 3, // onde a água nasce (no modo JOGO)
    TILE_OBJETIVO= 4
} Tile;

typedef enum { MODO_EDITOR = 0, MODO_JOGO = 1 } Modo;

typedef struct {
    int w, h;
    int tileSize;
    Tile *cells; // w*h
} Grade;

// --- Util ---
static inline int idx(Grade *g, int x, int y){ return y * g->w + x; }
static inline int in_bounds(Grade *g, int x, int y){ return x>=0 && x<g->w && y>=0 && y<g->h; }

static void GradeInit(Grade *g, int w, int h, int tile){
    g->w = w; g->h = h; g->tileSize = tile;
    g->cells = (Tile*)malloc(sizeof(Tile)*w*h);
    for(int i=0;i<w*h;i++) g->cells[i] = TILE_VAZIO;
}
static void GradeFree(Grade *g){
    free(g->cells); g->cells=NULL;
}
static void GradeLimpa(Grade *g){
    for(int i=0;i<g->w*g->h;i++) g->cells[i] = TILE_VAZIO;
}
static int ContaTile(Grade *g, Tile t){
    int c=0; for(int i=0;i<g->w*g->h;i++) if(g->cells[i]==t) c++;
    return c;
}

// --- Persistência simples ---
static int SalvaMapa(const char *path, Grade *g){
    FILE *f = fopen(path, "w");
    if(!f) return 0;
    fprintf(f, "%d %d\n", g->w, g->h);
    for(int y=0;y<g->h;y++){
        for(int x=0;x<g->w;x++) fprintf(f, "%d ", (int)g->cells[idx(g,x,y)]);
        fputc('\n', f);
    }
    fclose(f);
    return 1;
}
static int CarregaMapa(const char *path, Grade *g){
    FILE *f = fopen(path, "r");
    if(!f) return 0;
    int W,H;
    if(fscanf(f, "%d %d", &W, &H)!=2){ fclose(f); return 0; }
    if(W!=g->w || H!=g->h){
        Tile *novo = (Tile*)malloc(sizeof(Tile)*W*H);
        if(!novo){ fclose(f); return 0; }
        free(g->cells);
        g->cells = novo; g->w=W; g->h=H;
    }
    for(int y=0;y<g->h;y++)
        for(int x=0;x<g->w;x++){
            int v=0; if(fscanf(f, "%d", &v)!=1){ fclose(f); return 0; }
            g->cells[idx(g,x,y)] = (Tile)v;
        }
    fclose(f);
    return 1;
}

// --- Visual ---
static Color CorTile(Tile t){
    switch(t){
        case TILE_VAZIO:    return (Color){ 25, 25, 34, 255 };
        case TILE_TERRA:    return (Color){ 139, 90, 43, 255 };
        case TILE_ROCHA:    return GRAY;
        case TILE_FONTE:    return BLUE;
        case TILE_OBJETIVO: return GREEN;
        default: return BLACK;
    }
}

static void DesenhaTilemap(Grade *g, bool mostrarGrade){
    const int ts = g->tileSize;
    // blocos
    for(int y=0;y<g->h;y++){
        for(int x=0;x<g->w;x++){
            Rectangle r = (Rectangle){ x*ts, y*ts, ts, ts };
            DrawRectangleRec(r, CorTile(g->cells[idx(g,x,y)]));
        }
    }
    // grade (opcional, sutil)
    if(mostrarGrade){
        Color lc = (Color){255,255,255,30};
        for(int x=0;x<=g->w;x++) DrawLine(x*ts, 0, x*ts, g->h*ts, lc);
        for(int y=0;y<=g->h;y++) DrawLine(0, y*ts, g->w*ts, y*ts, lc);
    }
}

// Retorna novo "tile atual" se clicar num item do painel
static Tile DesenhaPainel(Grade *g, Tile atual, Modo modo, int painelX, int painelW, int pincelRaio){
    Rectangle painel = { (float)painelX, 0, (float)painelW, (float)(g->h*g->tileSize + 72) };
    DrawRectangleRec(painel, (Color){ 12,12,18,255 });

    int px = painelX + 14;
    int y  = 12;

    DrawText("MATERIAIS", px, y, 22, RAYWHITE); y += 28;

    struct Item { Tile t; const char *nome; int tecla; } itens[] = {
        {TILE_FONTE,    "Fonte (Água)", KEY_THREE},
        {TILE_TERRA,    "Terra",        KEY_ONE},
        {TILE_ROCHA,    "Rocha",        KEY_TWO},
        {TILE_OBJETIVO, "Objetivo",     KEY_FOUR},
        {TILE_VAZIO,    "Borracha (apagar)", 0}
    };

    Vector2 m = GetMousePosition();
    for(int i=0;i<5;i++){
        Rectangle box = { (float)px, (float)y, 28, 28 };
        Color c = CorTile(itens[i].t);
        DrawRectangleRec(box, c);
        DrawRectangleLinesEx(box, 2, (itens[i].t==atual)?YELLOW:(Color){255,255,255,60});
        DrawText(itens[i].nome, px + 40, y + 4, 18, RAYWHITE);
        if(itens[i].tecla){
            DrawText(TextFormat("[tecla %s]",
                (itens[i].tecla==KEY_ONE)?"1":
                (itens[i].tecla==KEY_TWO)?"2":
                (itens[i].tecla==KEY_THREE)?"3":"4"),
                px + 40, y + 22, 14, (Color){210,210,210,220});
        }
        if(CheckCollisionPointRec(m, box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            atual = itens[i].t;
        }
        y += 40;
    }

    y += 6;
    DrawText("PINCEL", px, y, 22, RAYWHITE); y += 26;
    DrawText("- [ e ]: diminuir/aumentar raio", px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText("- Scroll do mouse: ajusta raio",  px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText(TextFormat("Raio atual: %d tile%s", pincelRaio, (pincelRaio==1)?"":"s"), px, y, 18, YELLOW); y+=24;

    y += 4;
    DrawText("COMANDOS", px, y, 22, RAYWHITE); y += 26;
    DrawText("- Botão Esq.: pintar com material atual", px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText("- Botão Dir.: apagar (vazio)",           px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText("- 1: Terra | 2: Rocha | 3: Fonte | 4: Objetivo", px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText("- S: Salvar | L: Carregar | N: Novo",    px, y, 16, (Color){210,210,210,255}); y+=18;
    DrawText("- E: Modo Jogo | G: mostrar/ocultar grade", px, y, 16, (Color){210,210,210,255}); y+=18;

    y += 6;
    DrawText("MODO ATUAL", px, y, 22, RAYWHITE); y+=26;
    DrawText((modo==MODO_EDITOR)?"EDITOR":"JOGO", px, y, 22, (modo==MODO_EDITOR)?YELLOW:GREEN);

    return atual;
}

static const char* ValidaMapa(Grade *g){
    int f = ContaTile(g, TILE_FONTE);
    int o = ContaTile(g, TILE_OBJETIVO);
    if(f==0) return "Falta FONTE (tecla 3).";
    if(f>1)  return "Apenas UMA FONTE permitida.";
    if(o==0) return "Falta OBJETIVO (tecla 4).";
    if(o>1)  return "Apenas UM OBJETIVO permitido.";
    return NULL;
}

// --- Pintura com pincel circular ---
static void PintarComPincel(Grade *g, int cx, int cy, int raio, Tile mat){
    const int r2 = raio*raio;
    for(int dy=-raio; dy<=raio; dy++){
        for(int dx=-raio; dx<=raio; dx++){
            if(dx*dx + dy*dy > r2) continue; // círculo
            int x = cx + dx, y = cy + dy;
            if(!in_bounds(g, x, y)) continue;
            // unicidade de FONTE/OBJETIVO
            if(mat==TILE_FONTE){
                for(int i=0;i<g->w*g->h;i++) if(g->cells[i]==TILE_FONTE) g->cells[i]=TILE_VAZIO;
            } else if(mat==TILE_OBJETIVO){
                for(int i=0;i<g->w*g->h;i++) if(g->cells[i]==TILE_OBJETIVO) g->cells[i]=TILE_VAZIO;
            }
            g->cells[idx(g,x,y)] = mat;
        }
    }
}

int main(void){
    // "Pixels" pequenos -> tile de 8 px (160×90 => 1280×720 de mapa)
    const int TILE = 8;
    const int W = 160, H = 90;     // mapa 1280x720
    const int PAINEL_W = 320;      // painel largo
    const int WIN_W = W*TILE + PAINEL_W;
    const int WIN_H = H*TILE + 72; // barra inferior

    InitWindow(WIN_W, WIN_H, "Editor de Fase - PT-BR (Raylib)");
    SetTargetFPS(60);

    Grade g; GradeInit(&g, W, H, TILE);
    Modo  modo = MODO_EDITOR;
    Tile  atual = TILE_TERRA;
    int   pincelRaio = 2;                // em tiles (>=1)
    const int PINCEL_MIN = 1, PINCEL_MAX = 50;
    bool  mostrarGrade = false;

    char status[256] = "Editor: 1=Terra  2=Rocha  3=Fonte(Água)  4=Objetivo  |  [ e ]: raio  |  S/L/N  |  E: Jogo  |  G: grade";

    while(!WindowShouldClose()){
        // Alternar grade
        if(IsKeyPressed(KEY_G)) mostrarGrade = !mostrarGrade;

        // Alternar modo
        if(IsKeyPressed(KEY_E)){
            if(modo==MODO_EDITOR){
                const char* err = ValidaMapa(&g);
                if(err){ snprintf(status, sizeof(status), "Mapa inválido: %s", err); }
                else { modo = MODO_JOGO; snprintf(status,sizeof(status),"Jogo (placeholder). Volte com E."); }
            } else {
                modo = MODO_EDITOR;
                snprintf(status,sizeof(status),"Editor ativo. Pincel raio=%d. Use [ e ] ou Scroll.", pincelRaio);
            }
        }

        // Ajuste do pincel
        float wheel = GetMouseWheelMove();
        if(wheel > 0.0f) pincelRaio++;
        else if(wheel < 0.0f) pincelRaio--;
        if(IsKeyPressed(KEY_LEFT_BRACKET))  pincelRaio--;
        if(IsKeyPressed(KEY_RIGHT_BRACKET)) pincelRaio++;
        if(pincelRaio < PINCEL_MIN) pincelRaio = PINCEL_MIN;
        if(pincelRaio > PINCEL_MAX) pincelRaio = PINCEL_MAX;

        if(modo==MODO_EDITOR){
            // atalhos de material
            if(IsKeyPressed(KEY_ONE))   { atual = TILE_TERRA;     snprintf(status,sizeof(status),"Material: Terra | Raio=%d", pincelRaio); }
            if(IsKeyPressed(KEY_TWO))   { atual = TILE_ROCHA;     snprintf(status,sizeof(status),"Material: Rocha | Raio=%d", pincelRaio); }
            if(IsKeyPressed(KEY_THREE)) { atual = TILE_FONTE;     snprintf(status,sizeof(status),"Material: Fonte (Água) | Raio=%d", pincelRaio); }
            if(IsKeyPressed(KEY_FOUR))  { atual = TILE_OBJETIVO;  snprintf(status,sizeof(status),"Material: Objetivo | Raio=%d", pincelRaio); }

            // salvar/carregar/novo
            if(IsKeyPressed(KEY_S)){
                const char* err = ValidaMapa(&g);
                if(err){ snprintf(status,sizeof(status),"Não salvo: %s", err); }
                else if(SalvaMapa("map.lvl", &g)) snprintf(status,sizeof(status),"Salvo em map.lvl");
                else snprintf(status,sizeof(status),"Falha ao salvar");
            }
            if(IsKeyPressed(KEY_L)){
                if(CarregaMapa("map.lvl", &g)) snprintf(status,sizeof(status),"Mapa carregado de map.lvl");
                else snprintf(status,sizeof(status),"Falha ao carregar map.lvl");
            }
            if(IsKeyPressed(KEY_N)){
                GradeLimpa(&g); snprintf(status,sizeof(status),"Novo mapa limpo");
            }

            // Pintura (ignora cliques no painel)
            Vector2 m = GetMousePosition();
            int painelX = g.w*g.tileSize;
            if(m.x < painelX && m.y < g.h*g.tileSize){
                int gx = (int)m.x / g.tileSize;
                int gy = (int)m.y / g.tileSize;
                if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                    PintarComPincel(&g, gx, gy, pincelRaio, atual);
                } else if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)){
                    PintarComPincel(&g, gx, gy, pincelRaio, TILE_VAZIO);
                }
            }
        } else {
            // MODO_JOGO: simulação virá depois
        }

        // --- Desenho ---
        BeginDrawing();
            ClearBackground((Color){20,20,28,255});

            // mapa
            DesenhaTilemap(&g, mostrarGrade);

            // painel (pode mudar o "atual" ao clicar)
            int painelX = g.w*g.tileSize;
            atual = DesenhaPainel(&g, atual, modo, painelX, PAINEL_W, pincelRaio);

            // barra inferior (status)  >>> CORRIGIDO g.tileSize <<<
            Rectangle barra = (Rectangle){0, (float)(g.h*g.tileSize), (float)(g.w*g.tileSize + PAINEL_W), 72};
            DrawRectangleRec(barra, (Color){15,15,20,255});
            DrawText(status, 12, g.h*g.tileSize + 14, 18, RAYWHITE);

            // dica sob mouse
            Vector2 m = GetMousePosition();
            if(m.x < g.w*g.tileSize && m.y < g.h*g.tileSize){
                int gx = (int)m.x / g.tileSize;
                int gy = (int)m.y / g.tileSize;
                Tile t = g.cells[idx(&g,gx,gy)];
                const char* nome = (t==TILE_VAZIO)?"Vazio":
                                   (t==TILE_TERRA)?"Terra":
                                   (t==TILE_ROCHA)?"Rocha":
                                   (t==TILE_FONTE)?"Fonte (Água)":
                                   (t==TILE_OBJETIVO)?"Objetivo":"?";
                DrawText(TextFormat("(%d,%d) - %s | Raio=%d | Grade:%s",
                                    gx, gy, nome, pincelRaio, mostrarGrade?"ON":"OFF"),
                         12, g.h*g.tileSize + 40, 18, (Color){210,210,210,255});
            }
        EndDrawing();
    }

    GradeFree(&g);
    CloseWindow();
    return 0;
}
