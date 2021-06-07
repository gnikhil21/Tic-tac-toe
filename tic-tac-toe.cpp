# include<bits/stdc++.h>
using namespace std;

void display(char a[][5],char guide[][5])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
            cout<<guide[i][j];
        cout<<endl;
    }
}

pair<int,int> returnpos(char guide[][5],int pos)
{
    if(pos==1)
        return make_pair(0,0);
    else if(pos==2)
        return make_pair(0,2);
    else if(pos==3)
        return make_pair(0,4);
    else if(pos==4)
        return make_pair(1,0);
    else if(pos==5)
        return make_pair(1,2);
    else if(pos==6)
        return make_pair(1,4);
    else if(pos==7)
        return make_pair(2,0);
    else if(pos==8)
        return make_pair(2,2);
    else if(pos==9)
        return make_pair(2,4);
    return make_pair(10,10);
}

char check(char a[][5])
{
    int win=0;
    if(a[0][0]==a[0][2]&&a[0][2]==a[0][4])
        return a[0][0];
    else if(a[1][0]==a[1][2]&&a[1][2]==a[1][4])
        return a[1][0];
    else if(a[2][0]==a[2][2]&&a[2][2]==a[2][4])
        return a[2][0];
    else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0])
        return a[0][0];
    else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2])
        return a[0][2];
    else if(a[0][4]==a[1][4]&&a[1][4]==a[2][4])
        return a[0][4];
    else if(a[0][0]==a[1][2]&&a[1][2]==a[2][4])
        return a[0][0];
    else if(a[0][4]==a[1][2]&&a[1][2]==a[2][0])
        return a[0][4];
    return 'e';
}

int main(void) {

    char ans;
    do{
        char a[3][5]={
        {'_','|','_','|','_'},
        {'_','|','_','|','_'},
        {' ','|',' ','|',' '},
        };
        char guide[3][5]={
            {'1','|','2','|','3'},
            {'4','|','5','|','6'},
            {'7','|','8','|','9'},
        };
		int x=0,o=0,flag=0;
		int ele;
		pair<int,int>pos;
		while(1)
		{
			
			display(a,guide);
			cout<<endl;
			if(flag==0)
			{
				cout<<"Player 1 enter the position: ";
				cin>>ele;
				while(ele<=0||ele>9)
				{
					cout<<"Player 1 enter valid position: ";
					cin>>ele;
				}

				pos=returnpos(guide,ele);
				while(a[pos.first][pos.second]=='X'||a[pos.first][pos.second]=='O')
				{
					cout<<"Position already occupied!"<<endl<<"Player 1 enter valid position: ";
					cin>>ele;
					pos=returnpos(guide,ele);
				}
				a[pos.first][pos.second]='X';
				flag=1;
				x++;
			}
			else 
			{
				cout<<"Player 2 enter the position: ";
				cin>>ele;
				while(ele<=0||ele>9)
				{
					cout<<"Player 2 enter valid position: ";
					cin>>ele;
				}
				pos=returnpos(guide,ele);
				while(a[pos.first][pos.second]=='X'||a[pos.first][pos.second]=='O')
				{
					cout<<"Position already occupied!"<<endl<<"Player 2 enter valid position: ";
					cin>>ele;
					pos=returnpos(guide,ele);
				}
				a[pos.first][pos.second]='O';
				flag=0;
				o++;
			}
			char ch=check(a);
			
			if(ch=='X')
			{
				cout<<"Player 1 wins!!!"<<endl;
				break;
			}
			else if(ch=='O')
			{
				cout<<"Player 2 wins!!!"<<endl;
				break; 
			}
			if(x+o==9)
			{
				cout<<"Game drawed!!!"<<endl;
				break;
			}
		}
		
		cout<<"Do you want to play again (y/n): ";
		cin>>ans;
	}while(ans=='y');
    
	return 0;
}