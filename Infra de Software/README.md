## Infra de Software

This folder is focused on **concurrency, synchronization, and classic operating systems problems**, using practical implementations in C.

Unlike the numbered lists, which are mostly centered on algorithms and data structures, this section is much closer to **systems programming**, especially topics such as:

- threads;
- mutual exclusion;
- semaphores;
- condition variables;
- monitors;
- bounded buffers;
- coordination between multiple concurrent agents.

It is especially useful for understanding how concurrent programs behave in practice and how synchronization mechanisms are used to prevent race conditions, deadlocks, and incorrect shared-state access. 

---

### 1. Producer-Consumer with POSIX Threads

**Description:**  
Implements the classic **Producer-Consumer problem** using `pthread`, a bounded circular buffer, a mutex, and two condition variables: one for `not_full` and one for `not_empty`. The program supports multiple producers and multiple consumers, and uses a sentinel value to finish consumption cleanly. 

#### What this problem covers
- POSIX threads (`pthread`);
- bounded circular buffer;
- mutual exclusion with mutex;
- synchronization with condition variables;
- multiple producers and consumers;
- sentinel-based shutdown. 

#### What it is used for
This implementation is useful for studying one of the most important classic concurrency problems: coordinating producers and consumers over shared memory without overflowing or underflowing the buffer. 

#### What it strengthens
- shared-resource protection;
- correct use of `pthread_mutex_t`;
- correct use of `pthread_cond_wait` and `pthread_cond_signal`;
- circular buffer reasoning;
- graceful concurrent shutdown. 

#### Difficulty
**Medium to Hard**

The individual synchronization primitives are manageable, but combining them correctly in a multi-threaded bounded-buffer implementation requires careful reasoning about shared state and wake-up conditions. 

#### Complexity
- **Put item:** `O(1)`
- **Get item:** `O(1)`
- **Space:** `O(BUFFER_SIZE)`

> The main challenge here is not algorithmic complexity, but synchronization correctness under concurrency. 

---

### 2. Producer-Consumer with Windows Synchronization Primitives

**Description:**  
Implements the Producer-Consumer problem in a Windows environment using `CreateThread`, `CreateMutex`, and semaphores. The circular buffer is controlled by one semaphore for free slots and another for available items, with a mutex protecting the critical section. The shutdown logic uses a `POISON_PILL` marker. 

#### What this problem covers
- Windows threads;
- Windows mutexes;
- semaphores;
- critical sections over shared buffers;
- producer-consumer coordination;
- poison-pill termination. 

#### What it is used for
This implementation is useful for comparing concurrency design across platforms, showing how the same classic synchronization problem can be solved with Windows APIs instead of POSIX primitives. 

#### What it strengthens
- semaphore-based synchronization;
- Windows thread API familiarity;
- platform-specific concurrency understanding;
- synchronization of producers and consumers with bounded capacity. 

#### Difficulty
**Hard**

This version is conceptually similar to the POSIX producer-consumer solution, but the platform-specific APIs and explicit semaphore control make it a more systems-oriented exercise. 

#### Complexity
- **Deposit item:** `O(1)`
- **Remove item:** `O(1)`
- **Space:** `O(BUFFER_SIZE)`

> As with the POSIX version, the main difficulty lies in synchronization and correctness, not in raw asymptotic cost. 

---

### 3. Sleeping Barber Problem

**Description:**  
Implements the classic **Sleeping Barber problem** using `pthread`, a global monitor for the shop state, per-client condition variables, a waiting queue with limited capacity, and a queue of idle barbers. Clients either go directly to an idle barber, wait in the queue, or leave if the shop is full. Barbers sleep when there are no customers and wake up when new customers arrive. 

#### What this problem covers
- classic synchronization problem;
- monitors;
- condition variables;
- waiting-room capacity control;
- barber-client coordination;
- sleeping/waking thread behavior. 

#### What it is used for
This implementation is useful for studying a richer synchronization model than the bounded buffer, because it combines queue capacity, worker idleness, per-client coordination, and service completion signaling. 

#### What it strengthens
- monitor-style synchronization;
- multiple condition variables in the same system;
- thread coordination by state transitions;
- queue-based service simulation;
- concurrency modeling closer to real service systems. 

#### Difficulty
**Hard**

This is the most conceptually rich exercise in the folder, because it mixes bounded waiting, sleeping workers, direct assignment, FIFO queues, and per-client signaling in the same concurrent system. 

#### Complexity
- **Assign next client:** typically `O(1)`
- **Queue push/pop:** `O(1)`
- **Space:** `O(number of clients + waiting seats + barbers)`

> The real challenge is maintaining correct synchronization among all participants while preserving the intended shop behavior. 

---

## Summary of Infra de Software

Overall, `Infra de Software` strengthens topics such as:

- concurrency in C;
- thread creation and coordination;
- mutexes and semaphores;
- condition variables;
- bounded-buffer synchronization;
- classic synchronization problems;
- monitor-based design;
- operating systems and infrastructure-oriented reasoning. 

This makes the folder especially valuable for moving beyond pure algorithm practice and into **systems-level programming**, where correctness depends on how multiple threads interact over shared resources. 
