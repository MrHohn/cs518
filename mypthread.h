#ifndef H_MYPTHREAD
#define H_MYPTHREAD

#include <bits/pthreadtypes.h>
#include <bits/wordsize.h>
#include <sys/ucontext.h>

// ucontext_t coroutine_main;
// Types
typedef struct {
	// Define any fields you might need inside here.
	// static ucontext_t ctx;
	ucontext_t ctx;
	char st[8192];
} mypthread_t;

// typedef unsigned long int mypthread_t;

typedef struct {
	// Define any fields you might need inside here.
	int __detachstate;
	int __schedpolicy;
	// struct sched_param __schedparam;
	int __inheritsched;
	int __scope;
	size_t __guardsize;
	int __stackaddr_set;
	void * __stackaddr;
	size_t __stacksize;
} mypthread_attr_t;

// typedef union {
// 	// Define any fields you might need inside here.
// 	char __size[__SIZEOF_PTHREAD_ATTR_T];
// 	long int __align;
// } mypthread_attr_t;


// Functions
int mypthread_create(mypthread_t *thread, const mypthread_attr_t *attr,
			void *(*start_routine) (void *), void *arg);

void mypthread_exit(void *retval);

int mypthread_yield(void);

int mypthread_join(mypthread_t thread, void **retval);


/* Don't touch anything after this line.
 *
 * This is included just to make the mtsort.c program compatible
 * with both your ULT implementation as well as the system pthreads
 * implementation. The key idea is that mutexes are essentially
 * useless in a cooperative implementation, but are necessary in
 * a preemptive implementation.
 */

typedef int mypthread_mutex_t;
typedef int mypthread_mutexattr_t;

static inline int mypthread_mutex_init(mypthread_mutex_t *mutex,
			const mypthread_mutexattr_t *attr) { return 0; }

static inline int mypthread_mutex_destroy(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_lock(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_trylock(mypthread_mutex_t *mutex) { return 0; }

static inline int mypthread_mutex_unlock(mypthread_mutex_t *mutex) { return 0; }

#endif
