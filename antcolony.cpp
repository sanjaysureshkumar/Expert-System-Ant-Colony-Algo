#include <bits/stdc++.h>

using namespace std;

int main() {
	int n=100,dist1=0,op;
	//double dist2;
	//cin>>n;
	int best[n]={0};
	int alpha=2;
	int beta=4;
	int numiter=500;
	int numants=35;
	int pp=0;
	int min1=9999;
	int h=0;
	int i,j,sd,e[100][n];
	double c[n][n],d[n][n],b[n][n],efac,etotal,lll[n][n];
	float a[n][2],kk[n];
	int l=0;
	sd=1;
	efac=0.4;
	int y=sd-1;
	//sd=sd-1;
	
	srand(time(NULL));
	int mmm[n]={0,34,38,90,63,49,39,44,95,53,11,15,89,41,30,80,5,8,47,57,42,61,83,18,67,51,21,65,91,98,10,69,35,84,36,9,33,87,81,12,56,29,1,32,85,54,6,3,86,96,76,28,68,72,26,37,24,48,13,94,77,2,55,46,17,16,52,71,58,22,40,50,92,7,75,97,23,99,45,27,59,64,79,93,60,88,19,4,82,66,78,73,14,25,70,31,62,20,74,43};
	for(i=0;i<n;i++)
	{
		a[i][0]=rand()%100+10;
		a[i][1]=rand()%100+10;
		
	}
	for(i=0;i<n;i++)
	{
	    lll[i][i]=0;
	    b[i][i]=1;
	}
	for(i=0;i<n;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	    lll[i][j]=sqrt(pow(a[i][0]-a[j][0],2)+pow(a[i][1]-a[j][1],2));
	    lll[j][i]=lll[i][j];
	    b[i][j]=1;
	    b[j][i]=1;
	    }
	}
	int oo=0;
	for(i=0;i<100;i++)
	{
		oo+=lll[mmm[i]][mmm[(i+1)%n]];
	}
	cout<<oo;
	/*for(i=0;i<n;i++)
	{
	    for(j=0;j<1;j++)
	    {
	       cout<<a[i][j];
	    }
	    cout<<endl;
	}
	cout<<"---------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
	    for(j=1;j<2;j++)
	    {
	       cout<<a[i][j];
	    }
	    cout<<endl;
	}*/
	cout<<"---------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        if(i==j)
	        {
	            d[i][j]=0;
	        }
	        else
	        {
	        
	        d[i][j]=1/float(lll[i][j]);
	        }
	    }
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        if(i==j)
	        {
	            d[i][j]=0;
	        }
	        else
	        {
	        
	        d[i][j]=1/float(lll[i][j]);
	        }
	    }
	}
	
	int p[n];
	double k,cc,m,r,sum1;
	vector<double>m1,m2,dist2,m5,m6;
	vector<int>m3,m4;
	int u=0,mm;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
			b[i][j]=1;
			}
		}
		
		min1=9999;
		while(h<numiter)
		{
			u=0;
			while(u<numants)
			{
				sd=y;
				for(i=0;i<n;i++)
				{
					p[i]=0;
				}
				for(i=0;i<n;i++)
				{
	    			for(j=0;j<n;j++)
	    			{
		
	        			c[i][j]=d[i][j];
	        
	    			}			
				}
				for(i=0;i<n;i++)
				{
					m3.push_back(i);
				}
				m4.push_back(sd);
				m3.erase(m3.begin());
				while(l<n-1)
				{
					p[sd]=-1;
					for(i=0;i<n;i++)
					{
	    				c[i][sd]=0;
					}
	
					m=(rand()%100)/100.0;
	
					for(i=0;i<n;i++)
					{
	    				if(p[i]==0)
	    				{		 
	        				k=pow(b[sd][i],alpha);
	        				cc=pow(c[sd][i],beta);
	        				r=k*cc;
	        				m1.push_back(r);
	    				}
					}
					sum1=0;
					for(i=0;i<m1.size();i++)
					{
	   					sum1+=m1[i];
					}

					for(i=0;i<m1.size();i++)
					{
	    
	        			k=m1[i]/sum1;
	   					m2.push_back(k);
	   					if(i!=0)
	   					{
	   						m2[i]+=m2[i-1];
	   					}
					}
					i=0;
					while(i<n)
					{		
						if(i==0)
						{
							if(m<m2[i])
							{
								break;
							}
						}
						else
						{
							if(m>m2[i-1] && m<m2[i])
							{
							break;
							}
						}
						i++;
					}
					sd=m3[i];
					m4.push_back(sd);
					m3.erase(m3.begin()+(i));
					m1.clear();
					m2.clear();
	
					l++;
				}

				for(i=0;i<n;i++)
				{
					p[i]=0;
				}
				for(i=0;i<n;i++)
				{
					e[pp][i]=m4[i];
				}
				pp++;
				for(i=0;i<n;i++)
				{
					dist1+=lll[m4[i]][m4[(i+1)%n]];
				}
				m6.push_back(dist1);

				dist2.push_back(1/double(dist1));
				m5.push_back(min1);
				if(min1>dist1)
				{
					min1=dist1;
					
					for(i=0;i<n;i++)
					{
						best[i]=m4[i];
					}
				}
				
				l=0;
				m3.clear();
				m4.clear();
				//cout<<"Ant = "<<u<<endl<<"Dist this gen = "<<dist1<<endl;
				dist1=0;
				u++;
			}
			pp=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
				b[i][j]= (1-efac)*b[i][j];		
				}
			}
			for(i=0;i<numants;i++)
			{
				for(j=0;j<n;j++)
				{
					b[e[i][j]][e[i][(j+1)%n]]+= dist2[i];
					 
				}
			}
			u=0;
			/*for(i=0;i<100;i++)
			{
				cout<<"-";
			}*/
			dist2.clear();
			dist1=0;
			h++;
			//cout<<"Number of Iterations = "<<h<<endl;
		}
		//cout<<"Minimun dist = "<<min1<<" Evaporation factor = "<<efac<<endl;
		
	//cout<<endl;
	/*for(i=0;i<m6.size();i++)
	{
		cout<<m6[i]<<endl;
	}*/
	h=0;
	

	//cout<<"Min dist route = ";
		for(i=0;i<n;i++)
		{
		cout<<best[i]<<",";
		}
	return 0;
}


