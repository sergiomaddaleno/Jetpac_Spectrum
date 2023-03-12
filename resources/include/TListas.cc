

enum TPosition{
    previous,  //Para dejar puntero sobre el nodo aterior al localizado en la búsqueda y poder eliminar
    actual     //Para dejar puntero sobre el nodo localizado en la búsqueda
};

struct TNode{
	TBullet info;
	TNode *prox;
};

struct TNodeEnemies{
	TEnemies info;
	TNodeEnemies *prox;
};


#define TList TNode
#define TListEnemies TNodeEnemies

void CreateList(TNode **List){
	*List=nullptr;
}

void CreateListEnemies(TNodeEnemies **List){
	*List=nullptr;
}


bool IsemptyList(TNode *List){
    return (List==nullptr);
}

bool IsemptyListEnemies(TNodeEnemies *List){
    return (List==nullptr);
}

short InsertList(TNode **List, TBullet value){
    TNode *newnode;
    
    if((newnode=(TNode*)malloc(1*sizeof(TNode)))==nullptr){
        //No hay memoria
        return 0;
    } else{
            //Hay memoria
            newnode->info=value;
            newnode->prox=nullptr;
             if(IsemptyList(*List)){
                *List=newnode;
             } else{
                    newnode->prox=*List;
                    *List=newnode;
             }
             return 1;
    }          
}

short InsertListEnemies(TNodeEnemies **List, TEnemies value){
    TNodeEnemies *newnode;
    
    if((newnode=(TNodeEnemies*)malloc(1*sizeof(TNodeEnemies)))==nullptr){
        //No hay memoria
        return 0;
    } else{
            //Hay memoria
            newnode->info=value;
            newnode->prox=nullptr;
             if(IsemptyListEnemies(*List)){
                *List=newnode;
             } else{
                    newnode->prox=*List;
                    *List=newnode;
             }
             return 1;
    }          
}


//Ej si index es 3, Devuelve un puntero a una List al tercer elemento de la List
TNode *IndexaList(TNode *List,int index){ 
    TNode *p;

    if(index>=0 && !IsemptyList(List)){
      p=List;
      for(int i=0;p->prox!=nullptr && i<index;i++){
        p=p->prox;
      }
      return p;
    }
    else return nullptr;
}

//Busca un value en la List, si pos = previous nos devuelve el puntero al nodo previous
TNode *SearchList(TNode *List, TBullet value, TPosition pos){ 

    bool found=false;
    TNode *p=List;

    if(!IsemptyList(List)){
        do{
            switch(pos){//Detenemos localizado sobre el buscado o en el previous
                case   actual:found=(p->info.firstbullet==true); break;
                case previous:found=(p->prox->info.firstbullet==true); break;
            }
            if(!found) p=p->prox;//Cuando found no desplazo punter
        }while(!found && p!=nullptr);
        return p;//No found p = NULL
    }else{
        return nullptr;
    }
}  


void EliminaEnList(TNode **List, TBullet value){

	TNode *p,*q;
	if(!IsemptyList(*List)){
		 p=*List;
		 if(p->info.position.x==value.position.x){
		 	*List=p->prox;
		 	free(p);
		 }else{
		 	p=SearchList(*List,value,previous);
		 	q=p->prox;
		 	if(p!=nullptr){
		 		p->prox=q->prox;
		 		free(q);
		 	}
		 }

	}
   
}
