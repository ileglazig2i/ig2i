#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
/* ================================================================== */
/*                                                                    */
/* bal1.c                                                             */
/*                                                                    */
/* ================================================================== */
int infoQueue(int queueId)
{
struct msqid_ds buf;
msgctl(queueId,IPC_STAT,&buf);
printf("Informations sur la boite aux lettres %d  \n",queueId);
printf("msg_stime %s \n",ctime(&(buf.msg_stime)));
printf("msg_rstime %s \n",ctime(&(buf.msg_rtime)));
printf("msg_ctime %s \n",ctime(&(buf.msg_ctime)));
printf("msg_qnum %ld \n",buf.msg_qnum);
printf("msg_qbytes %ld \n",buf.msg_qbytes);
printf("msg_lspid %d \n",buf.msg_lspid);
printf("msg_lrpid %d \n",buf.msg_lrpid);
}
int main(int argc, char *argv[])
{
int balId;
struct msqid_ds buf;

key_t laClef;
laClef =ftok("bal1.c",1);
/* Creation de la boite aux lettres */

balId = msgget(laClef,IPC_CREAT | IPC_EXCL | 0666 );


/* Lecture des informations sur la boite aux lettres */
infoQueue(balId);

/* Ecriture d'un message dans la boite aux lettres */

/* Destruction de la boite aux lettres */
/* msgctl(balId,IPC_RMID,&buf);  */
/*while (1);*/

return 0;
}
