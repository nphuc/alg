#define FIBO
#define restrict __restrict
#include <malloc.h>
#include <memory.h>
#include <stdio.h>


typedef struct FiboLink_ {
  struct FiboNode_ *        prevptr;            
  struct FiboNode_ *        nextptr;             
} FiboLink;


typedef struct FiboNode_ {
  struct FiboNode_ *        pareptr;             
  struct FiboNode_ *        chldptr;              
  FiboLink                  linkdat;             
  int                       deflval;            
} FiboNode;

typedef struct FiboTree_ {
  FiboNode                  rootdat;
  FiboNode ** restrict      degrtab;
  int                    (* cmpfptr) (const FiboNode * const, const FiboNode * const); 
} FiboTree;


#define fiboTreeLinkAfter(o,n)      do {                              \
  FiboNode *        nextptr;      \
  nextptr = (o)->linkdat.nextptr; \
  (n)->linkdat.nextptr = nextptr; \
  (n)->linkdat.prevptr = (o);     \
  nextptr->linkdat.prevptr = (n); \
  (o)->linkdat.nextptr = (n);     \
} while (0)

#define fiboTreeUnlink(n)           do {                                                            \
  (n)->linkdat.prevptr->linkdat.nextptr = (n)->linkdat.nextptr; \
  (n)->linkdat.nextptr->linkdat.prevptr = (n)->linkdat.prevptr; \
} while (0)

#define fiboTreeAddMacro(t,n)       do {                                        \
  (n)->pareptr = NULL;                      \
  (n)->chldptr = NULL;                      \
  (n)->deflval = 0;                         \
  fiboTreeLinkAfter (&((t)->rootdat), (n)); \
} while (0)

#define fiboTreeMinMacro(t)         (fiboTreeConsolidate (t))

#define fiboTreeCutChildren(t,n)    do {                                                \
  FiboNode *        chldptr;                        \
  chldptr = (n)->chldptr;                           \
  if (chldptr != NULL) {                            \
    FiboNode *        cendptr;                      \
    cendptr = chldptr;                              \
    do {                                            \
      FiboNode *        nextptr;                    \
      nextptr = chldptr->linkdat.nextptr;           \
      chldptr->pareptr = NULL;                      \
      fiboTreeLinkAfter (&((t)->rootdat), chldptr); \
      chldptr = nextptr;                            \
    } while (chldptr != cendptr);                   \
  }                                                 \
} while (0)

#define fiboTreeDelMacro(t,n)       do {                                                    \
  FiboNode *        pareptr;                            \
  FiboNode *        rghtptr;                            \
  pareptr = (n)->pareptr;                               \
  fiboTreeUnlink (n);                                   \
  fiboTreeCutChildren ((t), (n));                       \
  if (pareptr == NULL)                                  \
  break;                                              \
  rghtptr = (n)->linkdat.nextptr;                       \
  while (1) {                                           \
    FiboNode *        gdpaptr;                          \
    int               deflval;                          \
    deflval = pareptr->deflval - 2;                     \
    pareptr->deflval = deflval | 1;                     \
    gdpaptr = pareptr->pareptr;                         \
    pareptr->chldptr = (deflval <= 1) ? NULL : rghtptr; \
    if (((deflval & 1) == 0) || (gdpaptr == NULL))      \
    break;                                            \
    rghtptr = pareptr->linkdat.nextptr;                 \
    fiboTreeUnlink (pareptr);                           \
    pareptr->pareptr = NULL;                            \
    fiboTreeLinkAfter (&((t)->rootdat), pareptr);       \
    pareptr = gdpaptr;                                  \
  }                                                     \
} while (0)


#define fiboTreeAdd                 fiboTreeAddMacro

#ifndef FIBO
#define static
#endif
int                         fiboTreeInit        (FiboTree * const, int (*) (const FiboNode * const, const FiboNode * const));
void                        fiboTreeExit        (FiboTree * const);
void                        fiboTreeFree        (FiboTree * const);
FiboNode *                  fiboTreeConsolidate (FiboTree * const);
#ifndef fiboTreeAdd
void                        fiboTreeAdd         (FiboTree * const, FiboNode * const);
#endif /* fiboTreeAdd */
#ifndef fiboTreeDel
void                        fiboTreeDel         (FiboTree * const, FiboNode * const);
#endif /* fiboTreeDel */
#ifndef fiboTreeMin
FiboNode *                  fiboTreeMin         (FiboTree * const);
#endif /* fiboTreeMin */
#ifdef FIBO_DEBUG
int                         fiboTreeCheck       (const FiboTree * const);
static int                  fiboTreeCheck2      (const FiboNode * const);
#endif /* FIBO_DEBUG */

#undef static

#ifndef INT
#define INT                         int           /* "long long" can be used on 64-bit systems */
#endif /* INT */

#ifndef errorPrint
#define errorPrint(s)               fprintf (stderr, s)
#endif /* errorPrint */

#ifndef memAlloc
#define memAlloc                    malloc
#define memSet                      memset
#define memFree                     free
#endif /* memAlloc */

/*********************************************/
/*                                           */
/* These routines deal with Fibonacci trees. */
/*                                           */
/*********************************************/

/* This routine initializes a Fibonacci
 ** tree structure.
 ** It returns:
 ** - 0   : in case of success.
 ** - !0  : on error.
 */

  int
fiboTreeInit (
    FiboTree * const            treeptr,
    int                      (* cmpfptr) (const FiboNode * const, const FiboNode * const))
{
  if ((treeptr->degrtab = (FiboNode **) memAlloc ((sizeof (INT) << 3) * sizeof (FiboNode *))) == NULL) /* As many cells as there are bits in an INT */
    return (1);

  memSet (treeptr->degrtab, 0, (sizeof (INT) << 3) * sizeof (FiboNode *)); /* Make degree array ready for consolidation: all cells set to NULL */

  treeptr->rootdat.linkdat.prevptr =              /* Link root node to itself */
    treeptr->rootdat.linkdat.nextptr = &treeptr->rootdat;
  treeptr->cmpfptr = cmpfptr;

  return (0);
}

/* This routine flushes the contents of
 ** the given Fibonacci tree.
 ** It returns:
 ** - VOID  : in all cases.
 */

  void
fiboTreeExit (
    FiboTree * const            treeptr)
{
  if (treeptr->degrtab != NULL)
    memFree (treeptr->degrtab);
}

/* This routine flushes the contents of
 ** the given Fibonacci tree. It does not
 ** free any of its contents, but instead
 ** makes the tree structure look empty again.
 ** It returns:
 ** - VOID  : in all cases.
 */

  void
fiboTreeFree (
    FiboTree * const            treeptr)
{
  treeptr->rootdat.linkdat.prevptr =              /* Link root node to itself */
    treeptr->rootdat.linkdat.nextptr = &treeptr->rootdat;
}

/* This routine perform the consolidation
 ** of roots per degree. It returns the best
 ** element found because this element is not
 ** recorded in the data structure itself.
 ** It returns:
 ** - !NULL  : pointer to best element found.
 ** - NULL   : Fibonacci tree is empty.
 */

  FiboNode *
fiboTreeConsolidate (
    FiboTree * const            treeptr)
{
  FiboNode ** restrict  degrtab;
  int                   degrmax;
  int                   degrval;
  FiboNode *            rootptr;
  FiboNode *            nextptr;
  FiboNode *            bestptr;

  degrtab = treeptr->degrtab;

  for (rootptr = treeptr->rootdat.linkdat.nextptr, nextptr = rootptr->linkdat.nextptr, degrmax = 0; /* For all roots in root list */
      rootptr != &treeptr->rootdat; ) {
    degrval = rootptr->deflval >> 1;              /* Get degree, getting rid of flag part */
#ifdef FIBO_DEBUG
    if (degrval >= (sizeof (INT) << 3))
      errorPrint ("fiboTreeConsolidate: invalid node degree");
#endif /* FIBO_DEBUG */
    if (degrtab[degrval] == NULL) {               /* If no tree with same degree already found */
      if (degrval > degrmax)                      /* Record highest degree found               */
        degrmax = degrval;

      degrtab[degrval] = rootptr;                 /* Record tree as first tree with this degree      */
      rootptr = nextptr;                          /* Process next root in list during next iteration */
      nextptr = rootptr->linkdat.nextptr;
    }
    else {
      FiboNode *            oldrptr;              /* Root which will no longer be a root */
      FiboNode *            chldptr;

      oldrptr = degrtab[degrval];                 /* Assume old root is worse           */
      if (treeptr->cmpfptr (oldrptr, rootptr) <= 0) { /* If old root is still better    */
        oldrptr = rootptr;                        /* This root will be be linked to it  */
        rootptr = degrtab[degrval];               /* We will go on processing this root */
      }

      degrtab[degrval] = NULL;                    /* Remaining root changes degree so leaves this cell */
      fiboTreeUnlink (oldrptr);                   /* Old root is no longer a root                      */
      oldrptr->deflval &= ~1;                     /* Whatever old root flag was, it is reset to 0      */
      oldrptr->pareptr = rootptr;                 /* Remaining root is now father of old root          */

      chldptr = rootptr->chldptr;                 /* Get first child of remaining root                                    */
      if (chldptr != NULL) {                      /* If remaining root had already some children, link old root with them */
        rootptr->deflval += 2;                    /* Increase degree by 1, that is, by 2 with left shift in deflval       */
        fiboTreeLinkAfter (chldptr, oldrptr);
      }
      else {                                      /* Old root becomes first child of remaining root */
        rootptr->deflval = 2;                     /* Real degree set to 1, and flag set to 0        */
        rootptr->chldptr = oldrptr;
        oldrptr->linkdat.prevptr =                /* Chain old root to oneself as only child */
          oldrptr->linkdat.nextptr = oldrptr;
      }
    }                                             /* Process again remaining root as its degree has changed */
  }

  bestptr = NULL;
  for (degrval = 0; degrval <= degrmax; degrval ++) {
    if (degrtab[degrval] != NULL) {               /* If some tree is found           */
      bestptr = degrtab[degrval];                 /* Record it as potential best     */
      degrtab[degrval] = NULL;                    /* Clean-up used part of array     */
      degrval ++;                                 /* Go on at next cell in next loop */
      break;
    }
  }
  for ( ; degrval <= degrmax; degrval ++) {       /* For remaining roots once a potential best root has been found */
    if (degrtab[degrval] != NULL) {
      if (treeptr->cmpfptr (degrtab[degrval], bestptr) < 0) /* If new root is better */
        bestptr = degrtab[degrval];               /* Record new root as best root    */
      degrtab[degrval] = NULL;                    /* Clean-up used part of array     */
    }
  }

  return (bestptr);
}

/* This routine returns the node of minimum
 ** key in the given tree. The node is searched
 ** for each time this routine is called, so this
 ** information should be recorded if needed.
 ** This is the non-macro version, for testing
 ** and setting up breakpoints.
 ** It returns:
 ** - !NULL  : pointer to best element found.
 ** - NULL   : Fibonacci tree is empty.
 */

#ifndef fiboTreeMin

  FiboNode *
fiboTreeMin (
    FiboTree * const            treeptr)
{
  FiboNode *            bestptr;

  bestptr = fiboTreeMinMacro (treeptr);

#ifdef FIBO_DEBUG
  fiboTreeCheck (treeptr);
#endif /* FIBO_DEBUG */

  return (bestptr);
}

#endif /* fiboTreeMin */

/* This routine adds the given node to the
 ** given tree. This is the non-macro version,
 ** for testing and setting up breakpoints.
 ** It returns:
 ** - void  : in all cases.
 */

#ifndef fiboTreeAdd

  void
fiboTreeAdd (
    FiboTree * const            treeptr,
    FiboNode * const            nodeptr)
{
  fiboTreeAddMacro (treeptr, nodeptr);

#ifdef FIBO_DEBUG
  fiboTreeCheck (treeptr);
#endif /* FIBO_DEBUG */
}

#endif /* fiboTreeAdd */

/* This routine deletes the given node from
 ** the given tree, whatever ths node is (root
 ** or non root). This is the non-macro version,
 ** for testing and setting up breakpoints.
 ** It returns:
 ** - void  : in all cases.
 */

#ifndef fiboTreeDel

  void
fiboTreeDel (
    FiboTree * const            treeptr,
    FiboNode * const            nodeptr)
{
  fiboTreeDelMacro (treeptr, nodeptr);

#ifdef FIBO_DEBUG
  nodeptr->pareptr =
    nodeptr->chldptr =
    nodeptr->linkdat.prevptr =
    nodeptr->linkdat.nextptr = NULL;

  fiboTreeCheck (treeptr);
#endif /* FIBO_DEBUG */
}

#endif /* fiboTreeDel */

/* This routine checks the consistency of the
 ** given linked list.
 ** It returns:
 ** - !NULL  : pointer to the vertex.
 ** - NULL   : if no such vertex available.
 */

#ifdef FIBO_DEBUG

static
  int
fiboTreeCheck2 (
    const FiboNode * const      nodeptr)
{
  FiboNode *            chldptr;
  int                   degrval;

  degrval = 0;
  chldptr = nodeptr->chldptr;
  if (chldptr != NULL) {
    do {
      if (chldptr->linkdat.nextptr->linkdat.prevptr != chldptr) {
        errorPrint ("fiboTreeCheck: bad child linked list");
        return     (1);
      }

      if (chldptr->pareptr != nodeptr) {
        errorPrint ("fiboTreeCheck: bad child parent");
        return (1);
      }

      if (fiboTreeCheck2 (chldptr) != 0)
        return (1);

      degrval ++;
      chldptr = chldptr->linkdat.nextptr;
    } while (chldptr != nodeptr->chldptr);
  }

  if (degrval != (nodeptr->deflval >> 1)) {       /* Real node degree is obtained by discarding lowest bit */
    errorPrint ("fiboTreeCheck2: invalid child information");
    return     (1);
  }

  return (0);
}

  int
fiboTreeCheck (
    const FiboTree * const      treeptr)
{
  FiboNode *            nodeptr;

  for (nodeptr = treeptr->rootdat.linkdat.nextptr;
      nodeptr != &treeptr->rootdat; nodeptr = nodeptr->linkdat.nextptr) {
    if (nodeptr->linkdat.nextptr->linkdat.prevptr != nodeptr) {
      errorPrint ("fiboTreeCheck: bad root linked list");
      return     (1);
    }

    if (nodeptr->pareptr != NULL) {
      errorPrint ("fiboTreeCheck: bad root parent");
      return (1);
    }

    if (fiboTreeCheck2 (nodeptr) != 0)
      return (1);
  }

  return (0);
}

#endif /* FIBO_DEBUG */


int main(){}
