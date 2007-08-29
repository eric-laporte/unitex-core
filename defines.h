
#ifndef custom_malloc
#define custom_malloc( T, S, V ) {                                    \
	(V) = (T *)malloc(sizeof(T) * (S));                               \
	if (! (V)) {                                                      \
		u_printf("Memory allocation error in %s:%d, exiting...\n\n"); \
		exit(1);                                                      \
	}                                                                 \
}
#endif

#ifndef STRINGINT
#define STRINGINT(_string, _int) { \
  char *_tmp; \
  long _number = strtol (_string, &_tmp, 0); \
  errno = 0; \
  if ((errno != 0 && _number == 0) || _string == _tmp || \
      (errno == ERANGE && (_number == LONG_MAX || _number == LONG_MIN))) \
    { \
      u_fprintf (stderr,"`%s' out of range", _string);; \
      exit (EXIT_FAILURE); \
    } \
  else \
  _int = (int) _number; \
}
#endif

#if 0

/* the anatomy of a judyhs array: (note that this version of judy is not official.
 * many undocumented features of this modified version were used in this package.
 */

PPvoid_t array   = NULL  // when a judy array is contained in another judy array,
                         // it's declared as PPvoid_t (which is just a void**) and used
                         // always like *array. otherwise, Pvoid_t is used. Note that a judy array
                         // should always be initialized to NULL, otherwise the first operation on 
                         // it will corrupt memory.
Pvoid_t  arrayI  = NULL; // iterator (ie pointer to an element, as in c++ map's iterator->second)
Pvoid_t  arrayK  = NULL; // key      (   pointer to an element's key, as in c++ map's iterator->first)
Pvoid_t  arrayS  = NULL; // state of the current iteration. should be NULLified before a new
                         // iteration is attempted, and should be destructed afterwards. 
Word_t   arraySL = 0;    // state length. is filled when the state is destroyed, so not of much use.
Word_t   arrayKL = 0;    // keylength
Word_t   arrayAL = 0;    // arraylength. is filled when the array is destroyed, so not of much use.
Word_t   arrayR  = 0;    // general-purpose return value. used generally for deletions.

#endif

#ifndef JUDY
#define _JUDYP(N,P) N ## P
#define JUDYLH( N )               \
	Pvoid_t  _JUDYP(N,I ) = NULL; \
	Word_t   _JUDYP(N,K ) = 0;    \
	Word_t   _JUDYP(N,AL) = 0;
#define JUDYHSH( N )              \
	Pvoid_t  _JUDYP(N,I ) = NULL; \
	Pvoid_t  _JUDYP(N,K ) = NULL; \
	Pvoid_t  _JUDYP(N,S ) = NULL; \
	Word_t   _JUDYP(N,SL) = 0;    \
	Word_t   _JUDYP(N,KL) = 0;    \
	Word_t   _JUDYP(N,AL) = 0;    \
	Word_t   _JUDYP(N,R)  = 0;
#endif


