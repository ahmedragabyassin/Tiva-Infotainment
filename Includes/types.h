/*
 * types.h
 *
 * Created: 2/13/2019 10:55:59 AM
 *  Author: Yassin
 */ 


#ifndef TYPES_H_
#define TYPES_H_

/************************************************************************/
/* Standard Types                                                       */
/************************************************************************/
typedef	unsigned char			uint8; 
typedef signed char				sint8;
typedef unsigned short			uint16;
typedef signed short			sint16;
typedef	unsigned long			uint32;
typedef	signed long				sint32;
typedef unsigned long long		uint64;
typedef signed long long		sint64;

/************************************************************************/
/* Pointers Standard types                                              */
/************************************************************************/			
typedef unsigned char *			ptr_8;
typedef unsigned short *		ptr_16;
typedef unsigned long *			ptr_32;
typedef unsigned long long *	ptr_64;

/************************************************************************/
/* define the void pointer to zero definition                           */
/************************************************************************/
#define NULL_PTR				((void *)0)

/************************************************************************/
/* define the abstraction of compiler keyword inline                    */
/************************************************************************/
#define INLINE					inline

/************************************************************************/
/* define the abstraction of compiler keyword static                    */
/************************************************************************/
#define STATIC					static

/************************************************************************/
/* define the local inline function                                     */
/************************************************************************/
#define STATIC_INLINE			static inline

#endif /* TYPES_H_ */