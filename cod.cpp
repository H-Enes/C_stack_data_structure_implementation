#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S{
	char data[30];
	int num=1;
};

S stack1[30], stack2[30];
char user_data[100];  // kullanıcının girdiği yapıyı kayıt edilen yer

int i=0;	 //char tipi datanın sayacı
int x=-1,y=0; //stack1 in sayacları
int st2=0;		// stack2 nin sayaci


printstack(){
	int m=0;
	printf("\n\tStack1: \n");
	
	for(m=x;m>=0; m--){
		printf("  %s : %d\n",stack1[m].data,stack1[m].num);
	}
	m=st2;
	if(stack2[0].data[0]==NULL){
		printf("\n\tStack2 : Bos\n");
	}
	else{
		printf("\n\n\tStack2: \n");
		for(m=st2-1; m>=0; m--){
			printf("  %s : %d\n",stack2[m].data,stack2[m].num);
		}
	}
}

get_stack2(){		// ')' geldiğinde '(' e kadar stack1 den çıkarıp stack2 ye ekleme
	int temp=0;
	while(stack1[x].data[0]!='('){
		stack2[st2]=stack1[x];
			while(stack1[x].data[temp]!=NULL){
				stack1[x].data[temp]='\0';
				temp++;
			}
			temp=0;
			st2++; 
			x--;
		}
		stack1[x].data[temp]='\0';
		x--;
		//st2--;	
}

get_stack1(){
	int parantez_ac_say;
	while(user_data[i]!=NULL){
		if(user_data[i]=='('){ // ( ise
			parantez_ac_say++;
			y=0;
			x++;
			stack1[x].data[0]=user_data[i];
			i++;
		}
		if(user_data[i]==')'){ // ) ise
			get_stack2();
			i++;
		}
		if(user_data [i]>='0' && user_data[i]<='9'){
			if(stack2[0].data[0]==NULL){				// stack2 bos ise
				stack1[x].num=user_data[i]-48;
				i++;
			}
			else{
				st2--;										// stack2 dolu ise
				int temp=0;
				int katsayi=user_data[i]-48;  // parantezin dışındaki sayi
				while(stack2[st2].data[0]!=NULL){

					stack2[st2].num=stack2[st2].num*katsayi;
					x++;
					stack1[x]=stack2[st2];
					while(stack2[st2].data[temp]!=NULL){
						stack2[st2].data[temp]='\0';
						temp++;
						
					}
					temp=0;
					if(st2>=0) {
						st2--;
					} 

				}										
				i++;
				st2=0;			
			} 
			  
			
		}		
		if(user_data[i]>='A' && user_data[i]<='Z'){ // büyük harf ise
			y=0;
			x++;
			stack1[x].data[y]=user_data[i];
			i++;
			y++;
		}
		if(user_data[i]>='a' && user_data[i]<='z'){
			stack1[x].data[y]=user_data[i];
			i++;
			y++;
		}
	}
}

int main(){
	
	printf("string dizisi giriniz: ");
	scanf("%s",user_data);
	
	get_stack1();
	printstack();

}


