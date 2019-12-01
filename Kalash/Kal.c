#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Rus");
	int n;
	int size;
	int count = 0;
	fflush(stdin);
	FILE *fin;
	fin = fopen("graph.txt","r+");
	
//==========================================================================
	printf("������� ���-�� ������: ");
	fscanf(fin,"%d",&n);
	fflush(stdin);
	size = (n*(n-1))/2;
	int L[size];
	int F[size];
	int T[size];
	int lft = 0;
	printf("������� ���������� ������ � ������������. ���� ������ ��� 30000\n");   //���� ������� ����������
	for(int i = 0; i<size; i++){
		fscanf(fin,"%d",&L[i]);
		if(L[i]>=30000){
			lft++;
		}
	}
//==========================================================================
	for( int i = 1; i<n; i++){
		for( int k = i+1; k<=n;k++){
			F[count]=i;
			T[count]=k;			// �������� ������� � �������
			count++;
		}
	}

//==========================================================================
	int min;
	for(int i=0;i<size-1;i++){
		min = i;
		for(int j=i+1;j<size;j++){
			if(L[j]<L[min]){
				min = j;
			}
		}						//��������� �������
		int t = L[i];
	    	L[i] = L[min];
		    L[min]=t;
	    	t = F[i];
	    	F[i] = F[min];
	    	F[min]=t;					//F - ������ �� size ���������, ������ ���������� �����
	    	t = T[i];					//T - ������ �� size ���������, ������ ���������� �����
	    	T[i] = T[min];					//L - ������ �� size ���������, ����� �����
	    	T[min]=t;
	}

//============================================================================
        size-=lft;
        //RE - ������� �������, ����� ����� � �������, � ������� ��������
        //i - ���������� ����� �����, ������� �� ����
        //MZ - ������������ �������� ��� ������� ����������� ������
		int RE = 0, MZ = size-(n-RE), i = 0;
		//Sres - ������ ������������� ���������, � ����� ������ ��������
		int Sres=99999999;
		//a[n] - ������ ������� ��������� �����
		int a[n];
		//ares[n] - ������ ����� �������������� ����������, � ����� ������ �������� �����
		int ares[n];
		//reb[n] - ������ ��������� ���� ������ � ������ ��� ������ �����
		int reb[n];
		for(int j = 0; j<n;j++)
			reb[j]=0;
		//C1,C2 - ������ ��� ������� ������ ����� (������ � ����� �������)
		//Q - ���-�� �������
		int Q = 0;
		a[0]=-1;
		int C1[n/2],C2[n/2];		//������� ����� ������ �� n/2 ���������. ��� ����� �������. � ��� ����� �������.
		//���� ��������
		//�������������, ���� ��� ������� ����� ��� ��������� ��������� ��� ��������� ��� ��������
		while(a[0]<=size-n&&i>=0){
		    //���� RE �������� ������������ �������� - ������������ � ������ ����������� �����
		    if(RE==MZ+1){
		    	if(i!=0){  
		    	    //������� � ������ ����������� �����
			    	i--;
			    	RE=a[i]+1;
			    	MZ=size-(n-i);
			    	reb[F[a[i]]-1]--;
			    	reb[T[a[i]]-1]--;
			    	//���������� ������������ �������
			    	Q=0;
			    	for(int j = 0; j<i;j++){
						//�������� a[j] � C. ���� �� ���.
						int check = 0;
						int k = 0;
						do{
							if(k==Q){
								C1[Q]=F[a[j]];
								C2[Q]=T[a[j]];
								Q++;
								check++;
							} else {
								if(F[a[j]]==C1[k]){
									C1[k]=T[a[j]];
									check++;
								} else if(T[a[j]]==C1[k]){
									C1[k]=F[a[j]];
									check++;
								} else if(F[a[j]]==C2[k]){
									C2[k]=T[a[j]];
									check++;
								} else if(T[a[j]]==C2[k]){
									C2[k]=F[a[j]];
									check++;
								}
							k++;
							}
						}while(check == 0);
						int o[n];
						int tr;
						for(int k = 0;k<n;k++)
							o[k]=0;
						for(int k = 0;k<Q;k++){
							o[C1[k]-1]++;
							o[C2[k]-1]++;
						}
						check = 0;
						for(int k = 0;k<n;k++){
							if(o[k]==2){
								tr=k+1;
								check++;
							}
						}
			    		if(check!=0){
				    		int pa=-1;
					    	int va=-1;
					    	k = 0;
					    	while(pa==-1){
					    		if(C1[k]==tr)
					    			pa=k;
					    		if(C2[k]==tr)
					    			pa=k;
					    		k++;
					    	}
    						while(va==-1){
    							if(C1[k]==tr)
    								va=k;
    							if(C2[k]==tr)
    								va=k;
    							k++;
    						}
				    		if(C1[pa]==C1[va]){
				    			C1[pa]=C2[va];
				    		}else if(C1[pa]==C2[va]){
				    			C1[pa]=C1[va];
				    		}else if(C2[pa]==C1[va]){
				    			C2[pa]=C2[va];
				    		}else if(C2[pa]==C2[va]){
				    			C2[pa]=C1[va];
				    		}
				    		for(k = va;k<Q-1;k++){
				    			C1[k]=C1[k+1];
				    			C2[k]=C2[k+1];
				    		}
				    		Q--;
				    	}
				    }
			    } else {
			            //����� ����������� ����� �� ����� ��������
			    		a[0]++;
		    	}
	    	}
	    	//����� ������������ RE
	    	else {
		            //�������� �� ����������� ������ �����
		        int check = 0;
		        //�������� ��������� ������, ���� ����������� ������� ����� ��������� 2 - ����� ����� �������� ������
			    for(int j = 0; j<n;j++){
			    	if(j+1==F[RE]&&reb[j]==2||j+1==T[RE]&&reb[j]==2){
				    	check++;
			    	}
			    }
			    //�������� �� ������������� - ���� �� ����������� ������� ����
    			for(int j = 0; j<Q;j++){
		    		if(F[RE]==C1[j]&&T[RE]==C2[j]||F[RE]==C2[j]&&T[RE]==C1[j]){
					check++;
			    	}
			    }
    			if(check==0){
    			//���� ����� ���������, ��������� - ����� �� ����� ��� ������������ �� �����
			    	int S = 0;
			    	for(int j = 0; j<i;j++)
			    		S+=L[a[j]];
			    	for(int j = RE;j<RE+(n-i);j++)
			    		S+=L[j];
			         //���� ����� - ��������, ���� ������ - ������������ � ����������� �����
			    	if(S<Sres){	
				//T(��������� ��� � a[i], ��������� reb, i++, RE++, MZ++.������ ������ ������� �� a[0]-a[i])
					a[i]=RE;
					reb[F[RE]-1]++;
					reb[T[RE]-1]++;
					i++;
					RE++;
					MZ++;
					check = 0;
					int k = 0;
					//printf("���� ����� %d: %d%d\n",i-1,F[RE-1],T[RE-1]);
					//���������� ����� � ��������
					do{
						if(k==Q){
							C1[Q]=F[a[i-1]];
							C2[Q]=T[a[i-1]];
							Q++;
							check++;
						} else {
							if(F[a[i-1]]==C1[k]){
								C1[k]=T[a[i-1]];
								check++;
							} else if(T[a[i-1]]==C1[k]){
								C1[k]=F[a[i-1]];
								check++;
							} else if(F[a[i-1]]==C2[k]){
								C2[k]=T[a[i-1]];
								check++;
							} else if(T[a[i-1]]==C2[k]){
								C2[k]=F[a[i-1]];
								check++;
							}
						k++;
						}
					}while(check == 0);
					//��������, ����� �� ��������� ��� ������� � ����
					int o[n];
					int tr;
					for(int k = 0;k<n;k++)
						o[k]=0;
					for(int k = 0;k<Q;k++){
						o[C1[k]-1]++;
						o[C2[k]-1]++;
					}
					check = 0;
					for(int k = 0;k<n;k++){
						if(o[k]==2){
							tr=k+1;
							check++;
						}
					}
		    		if(check!=0){
			    		int pa=-1;
				    	int va=-1;
				    	k = 0;
				    	while(pa==-1){
				    		if(C1[k]==tr)
				    			pa=k;
				    		if(C2[k]==tr)
				    			pa=k;
				    		k++;
				    	}
    					while(va==-1){
    						if(C1[k]==tr)
    							va=k;
    						if(C2[k]==tr)
    							va=k;
    						k++;
    					}
			    		if(C1[pa]==C1[va]){
			    			C1[pa]=C2[va];
			    		}else if(C1[pa]==C2[va]){
			    			C1[pa]=C1[va];
			    		}else if(C2[pa]==C1[va]){
			    			C2[pa]=C2[va];
			    		}else if(C2[pa]==C2[va]){
			    			C2[pa]=C1[va];
			    		}
			    		for(k = va;k<Q-1;k++){
			    			C1[k]=C1[k+1];
			    			C2[k]=C2[k+1];
			    		}
			    		Q--;
			    	}
				}
			    	else {
			    	    //���� ������ ����� ����� �� ����� - ��������� � ������ �����������
			        	//printf("�� ������ �� ����\n");
				      if(i!=0){
				    i--;
					RE=a[i]+1;
					MZ=size-(n-i);
					reb[F[a[i]]-1]--;
					reb[T[a[i]]-1]--;
					Q=0;
					//���������� �������
					for(int j = 0; j<i;j++){
						//�������� a[j] � C. ���� �� ���.
						int check = 0;
						int k = 0;
						do{
							if(k==Q){
								C1[Q]=F[a[j]];
								C2[Q]=T[a[j]];
								Q++;
								check++;
							} else {
								if(F[a[j]]==C1[k]){
									C1[k]=T[a[j]];
									check++;
								} else if(T[a[j]]==C1[k]){
									C1[k]=F[a[j]];
									check++;
								} else if(F[a[j]]==C2[k]){
									C2[k]=T[a[j]];
									check++;
								} else if(T[a[j]]==C2[k]){
									C2[k]=F[a[j]];
									check++;
								}
							k++;
							}
						}while(check == 0);
						int o[n];
						int tr;
						for(int k = 0;k<n;k++)
							o[k]=0;
						for(int k = 0;k<Q;k++){
							o[C1[k]-1]++;
							o[C2[k]-1]++;
						}
						check = 0;
						for(int k = 0;k<n;k++){
							if(o[k]==2){
								tr=k+1;
								check++;
							}
						}
			    		if(check!=0){
				    		int pa=-1;
					    	int va=-1;
					    	k = 0;
					    	while(pa==-1){
					    		if(C1[k]==tr)
					    			pa=k;
					    		if(C2[k]==tr)
					    			pa=k;
					    		k++;
					    	}
    						while(va==-1){
    							if(C1[k]==tr)
    								va=k;
    							if(C2[k]==tr)
    								va=k;
    							k++;
    						}
				    		if(C1[pa]==C1[va]){
				    			C1[pa]=C2[va];
				    		}else if(C1[pa]==C2[va]){
				    			C1[pa]=C1[va];
				    		}else if(C2[pa]==C1[va]){
				    			C2[pa]=C2[va];
				    		}else if(C2[pa]==C2[va]){
				    			C2[pa]=C1[va];
				    		}
				    		for(k = va;k<Q-1;k++){
				    			C1[k]=C1[k+1];
				    			C2[k]=C2[k+1];
				    		}
				    		Q--;
				    	}
					}}
				    	else{
				    	//����� �� �����
				        i--;
				    }
			    	}}
    			else {
			    RE++;
			    }
			    //���� �������� ����� ���� ����� - ���� ����������
    			if(i==n-1){
			    	int S = 0;
			    	int tarr[2];
			    	int tc = 0;
			    	for(int j = 0; j<n; j++){
			    		if(reb[j]==1){
			    			tarr[tc]=j+1;
			    			tc++;
			    		}
			    	}
			    	//printf("��� ����� %d: %d%d\n",i,tarr[0],tarr[1]);
			    	for(int j = 0; j<size;j++){
			    		if(tarr[0]==F[j]&&tarr[1]==T[j]||tarr[0]==T[j]&&tarr[1]==F[j]){
			    			a[n-1]=j;
			    			for(int k = 0;k<n;k++)
			    				S+=L[a[k]];
			    		}
			    	}
                 //� ���� ����� ���������� ������ �������� ����� - ���������
			    	if(S<Sres){
			    	    for(int j = 0; j<n;j++){
			    			ares[j]=a[j];
			    		}
			    		Sres=S;
			    	}
		        	i--;
                    RE=a[i]+1;
			    	MZ=size-(n-i);
			    	reb[F[a[i]]-1]--;
			    	reb[T[a[i]]-1]--;
			     	//����� ��������� �������
		        	for(int j = 0; j<i;j++){
					//�������� a[j] � C. ���� �� ���.
				int check = 0;
				int k = 0;
				do{
					if(k==Q){
						C1[Q]=F[a[j]];
						C2[Q]=T[a[j]];
						Q++;
						check++;
					} else {
						if(F[a[j]]==C1[k]){
							C1[k]=T[a[j]];
							check++;
						} else if(T[a[j]]==C1[k]){
							C1[k]=F[a[j]];
							check++;
						} else if(F[a[j]]==C2[k]){
							C2[k]=T[a[j]];
							check++;
				    	} else if(T[a[j]]==C2[k]){
							C2[k]=F[a[j]];
							check++;
						}
					k++;
					}
				}while(check == 0);
				int o[n];
				int tr;
				for(int k = 0;k<n;k++)
					o[k]=0;
				for(int k = 0;k<Q;k++){
					o[C1[k]-1]++;
					o[C2[k]-1]++;
				}
				check = 0;
				for(int k = 0;k<n;k++){
					if(o[k]==2){
						tr=k+1;
						check++;
					}
				}
			   	if(check!=0){
					int pa=-1;
				   	int va=-1;
				  	k = 0;
			    	while(pa==-1){
				   		if(C1[k]==tr)
				   			pa=k;
			    		if(C2[k]==tr)
			    			pa=k;
			    		k++;
			    	}
    				while(va==-1){
    					if(C1[k]==tr)
    						va=k;
    					if(C2[k]==tr)
    						va=k;
    					k++;
    				}
					if(C1[pa]==C1[va]){
						C1[pa]=C2[va];
					}else if(C1[pa]==C2[va]){
						C1[pa]=C1[va];
					}else if(C2[pa]==C1[va]){
				    	C2[pa]=C2[va];
					}else if(C2[pa]==C2[va]){
						C2[pa]=C1[va];
					}
					for(k = va;k<Q-1;k++){
						C1[k]=C1[k+1];
						C2[k]=C2[k+1];
					}
		    		Q--;
		    	}
		    }
		    	}
	    	}
		}
		//����� ������ � ����: "����������� �����" � ������ ������������ ����� (�� ������)
		printf("Sres %d\n",Sres);
		fclose(fin);
		for(int j = 0;j<n;j++){
			printf("%d%d, ",F[ares[j]],T[ares[j]]);
		}
		int tares[n+1];
		tares[0]=F[ares[0]];
		tares[1]=T[ares[0]];
		for(int j = 2; j<n+1;j++){
			int check = 0;
			for(int k = 1;k<n&&check==0;k++){
				if(F[ares[k]]==tares[j-1]&&T[ares[k]]!=tares[j-2]){
					tares[j]=T[ares[k]];
					check++;
					//printf("n");
				} else if(T[ares[k]]==tares[j-1]&&F[ares[k]]!=tares[j-2]){
					tares[j]=F[ares[k]];
					check++;
					//printf("k");
				}
			}
		}
		for(int j = 0;j<n+1;j++){
			printf("%d.",tares[j]);
		}
	system("pause");
}