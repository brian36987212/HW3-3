#include<iostream>
using namespace std;
int main()
{
	int ivtamount[100][100]={0},orderamount[100][100]={0},ivtuc=0,stockoutuc=0,inventory=0,stockoutday=0,totalcost=0,alltotalcost[100]={0};
	int day=0,dayorder[100]={0},startivtamount;
	int ivtcost[100][100]={0},stockoutcost[100][100]={0};
	int min=0,index=0;
	
	cin >> inventory >> ivtuc >> stockoutuc >> startivtamount;
	cin >> day;
	
	
	for(int i=1;i<=day;i++)
	{
		cin >> dayorder[i];
	}
	
	for(int c=0;c<=inventory;c++)
	{
	
	  for(int a=1;a<=day;a++)
	  {
	  	ivtamount[c][0]=startivtamount;
	    ivtamount[c][a]=ivtamount[c][a-1]-dayorder[a];
	    //cout << ivtamount[c][a]<< "=" <<ivtamount[c][a-1]<< "-" <<dayorder[a] <<"\n";
	   
	   		
	    if(ivtamount[c][a]<=c && ivtamount[c][a]>=0)
	    {
	   	    orderamount[c][a]=inventory-ivtamount[c][a];
	   	    ivtcost[c][a]=ivtamount[c][a]*ivtuc;
	   	    ivtamount[c][a]=orderamount[c][a]+ivtamount[c][a];
	        }
	   		
	    else if(ivtamount[c][a]<0)
	    {
	   		orderamount[c][a]=inventory-ivtamount[c][a];
	   		stockoutcost[c][a]=ivtamount[c][a]*(-stockoutuc);
			ivtamount[c][a]=orderamount[c][a]+ivtamount[c][a];
			stockoutday++;  
	  
	        }
	    
	    else if(ivtamount[c][a]>=0)
	   		ivtcost[c][a]=ivtamount[c][a]*ivtuc;
	   	
	   
	  
	   
	   
	   }
	   
	  for(int b=1;b<=day;b++)
	  {	
	    //cout << ivtcost[c][b] << " " << stockoutcost[c][b] << "\n";
		totalcost=ivtcost[c][b]+stockoutcost[c][b]+totalcost;
		
		//cout <<"totalcost =" << totalcost  << " \n";
	    }
	  
	  
	  alltotalcost[c]=totalcost;
	  totalcost=0,stockoutday=0;
	  cout << "c=" << c << " " << alltotalcost[c] << " " << totalcost << "\n"; 
	  
	  
	  
    }
	
	min=alltotalcost[0];
	
	for(int x=0;x<inventory;x++)//最低成本&最小s值 
	{
	  if(min>alltotalcost[x])
	  {
	  	min=alltotalcost[x];
	  	index=x;
	  }
	}
	   
	cout << index << "," << min;
	   
	   
	return 0;  
	
	
	
	
}
