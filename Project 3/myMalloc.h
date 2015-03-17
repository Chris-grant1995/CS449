//Chris Grant 
//Project 3 myMalloc and myFree
//Prof. Misurda
#include <stdio.h>
struct node {
        int nodeSize; 
        int used; 
        struct node *pNode; 
        struct node *nNode; 
};
struct node *fNode;//First Node in LL
struct node *lNode;//Last Node in LL


void * my_malloc(int size){
	void * returnPointer = NULL;
	struct node tempNode;
	


	if(size>0){
		int nodeSize= sizeof(struct node);
		size+=nodeSize;

		if(fNode==NULL)
		{
			fNode=sbrk(size);

			lNode=fNode;
			tempNode.nodeSize=size;
			tempNode.used=1;
			tempNode.pNode=NULL;//First Node being created, thus previous and next nodes are null
			tempNode.nNode=NULL;
			*fNode=tempNode;

			returnPointer= (void *) (fNode + sizeof(tempNode));
		}

		else{//Best Fit Algorithm 
			int perfectFit =0; // 1 for found, 0 for not found
			struct node *cNode= fNode; //Current node
			struct node *currentBestNode;
			struct node *bNode = NULL; //Best fit node
			int bestsize = 0; // Size of best fit node

			while(cNode!=NULL && !perfectFit){
				//While there is still items in the list and no perfect match is found
				if(!(cNode->used) ){ // If not being used
					if (cNode->nodeSize==size){
						perfectFit=1;
						bNode=cNode;
					}
					else if(cNode->nodeSize > size){
						if(cNode->nodeSize < bestsize || bestsize==0){
							currentBestNode = cNode;
							bestsize= cNode->nodeSize;
						}
						cNode = cNode->nNode;
					}
					else{
						cNode = cNode->nNode;
					}
				}
				else{
					cNode = cNode->nNode;
				}

			}
			if(currentBestNode!= NULL){
				if(perfectFit)
				{
					currentBestNode -> used = 1;
					returnPointer = (void *) (currentBestNode+ sizeof(tempNode));
				}
				else{
					cNode = (struct node *)(currentBestNode+size);

					tempNode.nodeSize = currentBestNode->nodeSize - size;
					tempNode.used = 0;
					tempNode.nNode = currentBestNode->nNode;
					tempNode.pNode= currentBestNode;

					*cNode = tempNode;

					currentBestNode -> nodeSize = size;
					currentBestNode -> used = 1;
					currentBestNode -> nNode = cNode;

					returnPointer = (void *)(currentBestNode+sizeof(tempNode));
				}
			} 
			else{
				currentBestNode = (struct node* )sbrk(size);

				tempNode.nodeSize=size;
				tempNode.used=1;
				tempNode.pNode= lNode;
				tempNode.nNode = NULL;
				*currentBestNode= tempNode;
				lNode->nNode= currentBestNode;
				lNode = currentBestNode;
				returnPointer = (void *) (currentBestNode+ sizeof(tempNode));
			}
		}
	}
	return returnPointer;


}
void my_free(void * p){
	int sbrkAmt;

	struct node *tempFree;

	struct node *tempPrev;
	struct node *tempNext;
	if(p != (void*) NULL)
	{
		tempFree = (struct node*)((char*) p-16); //-16 bc of heading 
		tempPrev = tempFree -> pNode;
		tempNext = tempFree -> nNode;
		if(tempNext = NULL){//If Node is at the end of the heap

			if(tempPrev == NULL) //If it is the only node in the heap
			{
				fNode =NULL;
				lNode = NULL;
				sbrk(0 - tempFree->nodeSize);
			}
			else{
				if(tempPrev -> used)
				{
					lNode= tempPrev;
					tempPrev -> nNode=NULL;
					sbrkAmt = 0 -tempFree->nodeSize;
					sbrk(sbrkAmt);
				}
				else{
					if(tempPrev->pNode == NULL)
					{
						fNode=NULL;
						lNode=NULL;
						sbrkAmt = 0 -tempFree->nodeSize;
						sbrkAmt-= tempPrev->nodeSize;
						sbrk(sbrkAmt);
					}
					else{
						lNode = tempPrev->pNode;
						tempPrev->pNode->nNode=NULL;
						sbrkAmt = 0 -tempFree->nodeSize;
						sbrkAmt-= tempPrev->nodeSize;
						sbrk(sbrkAmt);
					}
				}
			}
		}
		else{
			if(tempPrev!=NULL){
				if(tempPrev->used==0)
				{
					if(tempNext->used==0)
					{
						tempPrev->nNode= tempNext->nNode;
						tempNext->nNode->pNode=tempPrev;
						tempPrev->nodeSize+=tempFree->nodeSize + tempNext->nodeSize;
						tempPrev->used=0;
					}
					else{
						tempPrev->nNode=tempNext;
						tempNext->pNode=tempPrev;
						tempPrev->nodeSize+=tempFree->nodeSize;
						tempPrev->used=0;

					}
				}
				else if( tempNext->used==0)
				{
					tempFree->nNode=tempNext->nNode;
					tempNext->nNode->pNode=tempFree;
					tempFree->nodeSize += tempNext->nodeSize;
					tempFree->used =0;
				}
				else{
					tempFree->used=0;
				}
			}
			else{
				if(tempNext->used == 0)
				{
					tempFree->nNode=tempNext->nNode;
					tempNext->nNode->pNode=tempFree;
					tempFree->nodeSize+=tempNext->nodeSize;
					tempFree->used=0;
				}
				else{
					tempFree->used=0;
				}
			}
			
		}
	}
	
}