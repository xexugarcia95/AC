void suma_vector(int v[],int v_2[],const int n,const int N){
	int i;
	for(i=0;i<N;i++)
		v[i]=n*v_2[i]+v[i];
}