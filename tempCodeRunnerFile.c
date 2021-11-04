int folhas(Arv A){
    int n=0;
    if (A==NULL) return 0;
    else if (A->esq== NULL && A->dir == NULL) return 1;
    else return folhas(A->esq) + folhas(A->dir);
}