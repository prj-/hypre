/*BHEADER**********************************************************************
 * (c) 1998   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/
/******************************************************************************
 *
 *  Fake mpi stubs to generate serial codes without mpi
 *
 *****************************************************************************/

#ifndef hypre_MPISTUBS
#define hypre_MPISTUBS

#ifdef HYPRE_SEQUENTIAL

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------
 * Change all MPI names to hypre_MPI names to avoid link conflicts
 *
 * NOTE: MPI_Comm is the only MPI symbol in the HYPRE user interface,
 * and is defined in `HYPRE_utilities.h'.
 *--------------------------------------------------------------------------*/

#define MPI_Status          hypre_MPI_Status           
#define MPI_Request         hypre_MPI_Request          
#define MPI_Op              hypre_MPI_Op               
#define MPI_Datatype        hypre_MPI_Datatype         
#define MPI_Group           hypre_MPI_Group            
#define MPI_Aint            hypre_MPI_Aint             

#define MPI_COMM_WORLD      hypre_MPI_COMM_WORLD       

#define MPI_BOTTOM  	    hypre_MPI_BOTTOM

#define MPI_DOUBLE          hypre_MPI_DOUBLE           
#define MPI_INT             hypre_MPI_INT              
#define MPI_CHAR            hypre_MPI_CHAR             
#define MPI_LONG            hypre_MPI_LONG             

#define MPI_SUM             hypre_MPI_SUM              
#define MPI_MIN             hypre_MPI_MIN              
#define MPI_MAX             hypre_MPI_MAX              
#define MPI_LOR             hypre_MPI_LOR              

#define MPI_UNDEFINED       hypre_MPI_UNDEFINED        
#define MPI_REQUEST_NULL    hypre_MPI_REQUEST_NULL        
#define MPI_ANY_SOURCE      hypre_MPI_ANY_SOURCE        

#define MPI_Init            hypre_MPI_Init             
#define MPI_Wtime           hypre_MPI_Wtime            
#define MPI_Wtick           hypre_MPI_Wtick            
#define MPI_Barrier         hypre_MPI_Barrier          
#define MPI_Finalize        hypre_MPI_Finalize         
#define MPI_Comm_group      hypre_MPI_Comm_group       
#define MPI_Comm_dup        hypre_MPI_Comm_dup         
#define MPI_Group_incl      hypre_MPI_Group_incl       
#define MPI_Comm_create     hypre_MPI_Comm_create      
#define MPI_Allgather       hypre_MPI_Allgather        
#define MPI_Allgatherv      hypre_MPI_Allgatherv       
#define MPI_Gather          hypre_MPI_Gather       
#define MPI_Scatter         hypre_MPI_Scatter       
#define MPI_Bcast           hypre_MPI_Bcast            
#define MPI_Send            hypre_MPI_Send             
#define MPI_Recv            hypre_MPI_Recv             
#define MPI_Isend           hypre_MPI_Isend            
#define MPI_Irecv           hypre_MPI_Irecv            
#define MPI_Wait            hypre_MPI_Wait             
#define MPI_Waitall         hypre_MPI_Waitall          
#define MPI_Waitany         hypre_MPI_Waitany          
#define MPI_Comm_size       hypre_MPI_Comm_size        
#define MPI_Comm_rank       hypre_MPI_Comm_rank        
#define MPI_Allreduce       hypre_MPI_Allreduce        
#define MPI_Address         hypre_MPI_Address        
#define MPI_Type_contiguous hypre_MPI_Type_contiguous     
#define MPI_Type_hvector    hypre_MPI_Type_hvector     
#define MPI_Type_struct     hypre_MPI_Type_struct      
#define MPI_Type_free       hypre_MPI_Type_free        
#define MPI_Type_commit     hypre_MPI_Type_commit
#define MPI_LOR             hypre_MPI_LOR

/*--------------------------------------------------------------------------
 * Types, etc.
 *--------------------------------------------------------------------------*/

typedef struct { int MPI_SOURCE; } hypre_MPI_Status;
typedef int  hypre_MPI_Request;
typedef int  hypre_MPI_Op;
typedef int  hypre_MPI_Datatype;
typedef int  hypre_MPI_Group;
typedef int  hypre_MPI_Aint;

#define  hypre_MPI_COMM_WORLD 0

#define  hypre_MPI_BOTTOM  0x0

#define  hypre_MPI_DOUBLE 0
#define  hypre_MPI_INT 1
#define  hypre_MPI_CHAR 2
#define  hypre_MPI_LONG 3

#define  hypre_MPI_SUM 0
#define  hypre_MPI_MIN 1
#define  hypre_MPI_MAX 2
#define  hypre_MPI_LOR 3

#define  hypre_MPI_UNDEFINED -9999
#define  hypre_MPI_REQUEST_NULL  0
#define  hypre_MPI_ANY_SOURCE    1

/*--------------------------------------------------------------------------
 * Prototypes
 *--------------------------------------------------------------------------*/

/* mpistubs.c */
int MPI_Init( int *argc , char ***argv );
double MPI_Wtime( void );
double MPI_Wtick( void );
int MPI_Barrier( MPI_Comm comm );
int MPI_Finalize( void );
int MPI_Abort( MPI_Comm comm , int errorcode );
int MPI_Comm_group( MPI_Comm comm , MPI_Group *group );
int MPI_Comm_dup( MPI_Comm comm , MPI_Comm *newcomm );
int MPI_Group_incl( MPI_Group group , int n , int *ranks , MPI_Group *newgroup );
int MPI_Comm_create( MPI_Comm comm , MPI_Group group , MPI_Comm *newcomm );
int MPI_Get_count( MPI_Status *status , MPI_Datatype datatype , int *count );
int MPI_Alltoall( void *sendbuf , int sendcount , MPI_Datatype sendtype , void *recvbuf , int recvcount , MPI_Datatype recvtype , MPI_Comm comm );
int MPI_Allgather( void *sendbuf , int sendcount , MPI_Datatype sendtype , void *recvbuf , int recvcount , MPI_Datatype recvtype , MPI_Comm comm );
int MPI_Allgatherv( void *sendbuf , int sendcount , MPI_Datatype sendtype , void *recvbuf , int *recvcounts , int *displs , MPI_Datatype recvtype , MPI_Comm comm );
int MPI_Gather( void *sendbuf , int sendcount , MPI_Datatype sendtype , void *recvbuf , int recvcount , MPI_Datatype recvtype , int root , MPI_Comm comm );
int MPI_Scatter( void *sendbuf , int sendcount , MPI_Datatype sendtype , void *recvbuf , int recvcount , MPI_Datatype recvtype , int root , MPI_Comm comm );
int MPI_Bcast( void *buffer , int count , MPI_Datatype datatype , int root , MPI_Comm comm );
int MPI_Send( void *buf , int count , MPI_Datatype datatype , int dest , int tag , MPI_Comm comm );
int MPI_Recv( void *buf , int count , MPI_Datatype datatype , int source , int tag , MPI_Comm comm , MPI_Status *status );
int MPI_Isend( void *buf , int count , MPI_Datatype datatype , int dest , int tag , MPI_Comm comm , MPI_Request *request );
int MPI_Irecv( void *buf , int count , MPI_Datatype datatype , int source , int tag , MPI_Comm comm , MPI_Request *request );
int MPI_Wait( MPI_Request *request , MPI_Status *status );
int MPI_Waitall( int count , MPI_Request *array_of_requests , MPI_Status *array_of_statuses );
int MPI_Waitany( int count , MPI_Request *array_of_requests , int *index , MPI_Status *status );
int MPI_Comm_size( MPI_Comm comm , int *size );
int MPI_Comm_rank( MPI_Comm comm , int *rank );
int MPI_Allreduce( void *sendbuf , void *recvbuf , int count , MPI_Datatype datatype , MPI_Op op , MPI_Comm comm );
int MPI_Address( void *location , MPI_Aint *address );
int MPI_Type_contiguous( int count , MPI_Datatype oldtype , MPI_Datatype *newtype );
int MPI_Type_vector( int count , int blocklength , int stride , MPI_Datatype oldtype , MPI_Datatype *newtype );
int MPI_Type_hvector( int count , int blocklength , MPI_Aint stride , MPI_Datatype oldtype , MPI_Datatype *newtype );
int MPI_Type_struct( int count , int *array_of_blocklengths , MPI_Aint *array_of_displacements , MPI_Datatype *array_of_types , MPI_Datatype *newtype );
int MPI_Type_free( MPI_Datatype *datatype );
int MPI_Type_commit( MPI_Datatype *datatype );
int MPI_Request_free( MPI_Request *request );
int MPI_Send_init( void *buf , int count , MPI_Datatype datatype , int dest , int tag , MPI_Comm comm , MPI_Request *request );
int MPI_Recv_init( void *buf , int count , MPI_Datatype datatype , int dest , int tag , MPI_Comm comm , MPI_Request *request );
int MPI_Startall( int count , MPI_Request *array_of_requests );
int MPI_Iprobe( int source , int tag , MPI_Comm comm , int *flag , MPI_Status *status );
int MPI_Probe( int source , int tag , MPI_Comm comm , MPI_Status *status );
int MPI_Irsend( void *buf , int count , MPI_Datatype datatype , int dest , int tag , MPI_Comm comm , MPI_Request *request );

#ifdef __cplusplus
}
#endif

#endif

#endif
