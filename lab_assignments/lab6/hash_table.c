#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define NumItems 20
#define MinTableSize (10)

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry {
    int Element;
    enum KindOfEntry Info;
};
typedef unsigned int Index;
typedef Index Position;
typedef struct HashEntry Cell;

        /* Cell *TheCells will be an array of */
        /* HashEntry cells, allocated later */
struct HashTbl {
    int TableSize;
    Cell *TheCells;
};
typedef struct HashTbl *HashTable;
        /* Hash function for ints */
IndexHash( int Key, int TableSize ) {
    return Key % TableSize;
}

 /* Return next prime; assume N >= 10 */

static int NextPrime( int N ) {
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 ) {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
            printf("\nnext prime%d\n",N);
            return N;
            ContOuter: ;
    }
        }
        HashTable
        InitializeTable( int TableSize )
        {
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize )
            {
/* 2*/          printf( "Table size too small" );
/* 3*/          return NULL;
            }

            /* Allocate table */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          printf( "Out of space!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

            /* Allocate array of Cells */
/* 8*/      H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
/* 9*/      if( H->TheCells == NULL )
/*10*/          printf( "Out of space!!!" );

/*11*/      for( i = 0; i < H->TableSize; i++ )
/*12*/          H->TheCells[ i ].Info = Empty;

/*13*/      return H;
        }

        Position
        Find( int Key, HashTable H )
        {
            Position CurrentPos;
            int CollisionNum;

/* 1*/      CollisionNum = 0;
/* 2*/      CurrentPos = Hash( Key, H->TableSize );
            //printf( "CurrentPos %d\n", CurrentPos );
/* 3*/      while( H->TheCells[ CurrentPos ].Info != Empty &&
                   H->TheCells[ CurrentPos ].Element != Key )
                            /* Probably need strcmp!! */
            {
/* 4*/          CurrentPos += 2 * ++CollisionNum - 1;
/* 5*/          if( CurrentPos >= H->TableSize )
/* 6*/              CurrentPos -= H->TableSize;
            }
/* 7*/      return CurrentPos;
        }

        void
        Insert( int Key, HashTable H )
        {
            Position Pos;

            Pos = Find( Key, H );
            if( H->TheCells[ Pos ].Info != Legitimate )
            {
                /* OK to insert here */
                H->TheCells[ Pos ].Info = Legitimate;
                H->TheCells[ Pos ].Element = Key;
                         /* Probably need strcpy! */
            }
        }

        HashTable
        Rehash( HashTable H )
        {
            int i, OldSize;
            Cell *OldCells;

/* 1*/      OldCells = H->TheCells;
/* 2*/      OldSize  = H->TableSize;

            /* Get a new, empty table */
/* 3*/      H = InitializeTable( 2 * OldSize );

            /* Scan through old table, reinserting into new */
/* 4*/      for( i = 0; i < OldSize; i++ )
/* 5*/          if( OldCells[ i ].Info == Legitimate )
/* 6*/              Insert( OldCells[ i ].Element, H );

/* 7*/      free( OldCells );

/* 8*/      return H;
        }

        int
        Retrieve( Position P, HashTable H )
        {
            printf("\t%d",H->TheCells[ P ].Element);
            return H->TheCells[ P ].Element;
        }

        void
        DestroyTable( HashTable H )
        {
            free( H->TheCells );
            free( H );
        }
main( )
{
    HashTable H;
    Position P;
    int i;
    int CurrentSize;

    H = InitializeTable( CurrentSize = 11 );

    for( i = 0; i < NumItems; i++ )
    {
        if( i > CurrentSize / 2 )
        {
            H = Rehash( H );
            printf( "\nRehashing...\n" );
            CurrentSize *= 2;
        }
        Insert( i, H );
    }
    printf( "\nElements in Hash Table are...\n" );
    for( i = 0; i < NumItems; i++ )
        if( Retrieve( ( P = Find( i, H ) ), H ) != i )
            printf( "Error at %d\n", i );

    printf( "End of program.\n" );
    return 0;

}