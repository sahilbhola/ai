#include<iostream>
#include<stdlib.h>
using namespace std;
int main();
int turn,ch,b[10]={0,2,2,2,2,2,2,2,2,2},com[5],hum[5],mg[10]={0,8,3,4,1,5,9,6,7,2};

char a[10],y='y';
void update(){
	for(int i=1;i<10;i++){
		if(b[i]==2){
			a[i]=' ';
		}
		if(b[i]==3){
			a[i]='X';
		}
		if(b[i]==5){
			a[i]='O';
		}
	}
}
void move(int x){
	if(b[x]==2){
		b[x]=3;
		update();
		for(int i=1;i<5;i++){
			if(com[i]==0){
			com[i]=mg[x];
			break;
		}
		}
	}
	else{
	cout<<"\nwrong move";
	exit(1);
}


}
void go(int x){
	if(b[x]==2){
		b[x]=5;
		update();
		for(int i=1;i<5;i++){
			if(hum[i]==0){
			  hum[i]=mg[x];
			  break;
		    }
		}
	}
	else{
		cout<<"\nWrong move..\n";
		int y;
		cin>>y;
		go(y);
    }
}
void printBoard(){
	//system("clear");
	cout<<"PLAYER=O\tCOMPUTER=X\n\n";

	cout<<"\t\t "<<a[1]<<" | "<<a[2]<<" | "<<a[3];
	cout<<"\n\t\t___________\n";
	cout<<"\t\t "<<a[4]<<" | "<<a[5]<<" | "<<a[6];
    cout<<"\n\t\t___________\n";
	cout<<"\t\t "<<a[7]<<" | "<<a[8]<<" | "<<a[9]<<"\n\n";
	if(turn==8&&ch==1){
            cout<<"\n____YOU DID'NT WIN_____\n";
            cout<<"wanna play again ? (y/n)";
		           cin>>y;
		           if(y=='y'){
					   for(int f=1;f<10;f++){
                         b[f]=2;
                         com[f]=0;
                         hum[f]=0;
					   }
		              update();
		           }
		           else
                    exit(0);
	}
		       else if(turn==9){
            cout<<"\n____YOU DID'NT WIN_____\n";
            cout<<"wanna play again ? (y/n)";
		           cin>>y;
		           if(y=='y'){
					   for(int f=1;f<10;f++){
                         b[f]=2;
                         com[f]=0;
                         hum[f]=0;
					   }
		              update();
		           }
		           else
                    exit(0);
		       }




}
bool block(){
	for(int i=1;i<5;i++){
		for(int j=i+1;j<5;j++){
			   for(int f=1;f<10;f++){
			      if((mg[f]==15-(hum[i]+hum[j])) && (b[f]==2) && (hum[i]!=hum[j]) && hum[j]!=0){
			      move(f);
			      return true;

			   }
		   }
	   }
   }
   return false;
}
void posswin(){
	for(int i=1;i<5;i++){
		for(int j=i+1;j<5;j++){
			   for(int f=1;f<10;f++){
			      if((mg[f]==15-(com[i]+com[j])) && (b[f]==2) && (com[i]!=com[j])&&y!='y'&&com[j]!=0){
			      move(f);
			      printBoard();
		          cout<<"\n\t____YOU lost___\n";
		          cout<<"wanna play again ? (y/n)";
		          cin>>y;
		          if(y=='y'){
					  for(int g=1;g<10;g++){
		              b[g]=2;
		              com[g]=0;
		              hum[g]=0;
				  }
		              update();
		           }

		           else exit(0);
			   }
		   }
	   }
   }
}




void fill(){
	for(int i=1;i<10;i++){
		if(b[i]==2){
		    move(i);
		    break;
		}
	}

}
void cpu(){
	switch(turn){
		case 1:
		move(5);
	    break;

		case 2:
		if(b[5]==2)
			move(5);
			else move(1);
		break;

		case 3:
		if(b[2]==5||b[4]==5)
		move(9);
		else if(b[6]==5||b[8]==5)
		move(1);
		else if(b[1]==5)
		move(9);
		else if(b[9]==5)
		move(1);
		else if(b[3]==5)
		move(7);
		else if(b[7]==5)
		move(3);
		break;

		case 4:
		if(block())
		break;
		if(b[5]==5)
			move(3);
			else if((b[4]==5&&b[8]==5)||(b[4]==5&&b[3]==5)||(b[4]==5&&b[2]==5)||(b[4]==5&&b[9]==5)||(b[1]==5&&b[8]==5))
			move(7);
		    else {
		    for(int i=1;i<9;i++){
				if(hum[1]+hum[2]==10&&b[4]==2)
			{
				move(4);
				break;
			}
				else if(hum[1]+hum[2]==10&&b[2]==2)
			{
				move(2);
				break;
			}

				else if(i==8&&b[3]==2)
				move(3);
				else if(i==8)move(9);
			}
			}

		break;

		case 5:
		posswin();
		if(block()&&y!='y')
		break;
		if(y!='y')
	    fill();
		break;

		case 6:
		posswin();
		if(block()&&y!='y')
		break;
		if(y!='y')
		 fill();
		break;

		case 7:
		posswin();
		if(block()&&y!='y')
		break;
		if(y!='y')
		fill();
		break;

		case 8:
		posswin();
		if(block()&&y!='y')
		break;
		if(y!='y')
		fill();
		break;

		case 9:
		posswin();
		if(block()&&y!='y')
		break;
		if(y!='y')
		fill();
		break;
	}
}

int main(){
	int p;
	cout<<"\t----INSTRUCTIONS-----\n\n"<<"-To choose a Box just press the digit assigned to it\n\n";
	cout<<"\t\t "<<"1 | "<<"2 | 3";
	cout<<"\n\t\t___________\n";
	cout<<"\t\t "<<"4 | "<<"5 | 6";
    cout<<"\n\t\t___________\n";
	cout<<"\t\t "<<"7 | "<<"8 | 9"<<"\n______________________________________________________\n";
	while(y=='y'){
		y='n';
	cout<<"You wish to play 1st or 2nd ? ";
	cin>>ch;
	for(turn=1;turn<10;turn++){
		if(ch==1&&turn%2==0&&y=='n'){
		    cpu();
			printBoard();
		}
		else if(ch==1&&turn%2==1&&y=='n'){
			   update();
			   //printBoard();
			   if(turn!=9){
			   cin>>p;
			   go(p);
			   printBoard();
			   }
		}
		if(ch==2&&turn%2==1&&y=='n'){
		    cpu();
			printBoard();
		}
		else if(ch==2&&turn%2==0&&y=='n'){
			   cin>>p;
			   go(p);
			   printBoard();
		}
	}
}

	return 0;
}
