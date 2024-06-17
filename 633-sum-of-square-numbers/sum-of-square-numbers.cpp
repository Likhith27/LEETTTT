class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        // int flag=0;
        // for(int i=0;i<=c;i++)
        // {
        //     for(int j=0;j<=c;j++)
        //     {
        //         if(i*i + j*j==c)
        //             flag=1;
        //     }

        // }
        // return flag==1;
        if(c<0)
    		return false;

    	long int i=0,j=sqrt(c);

    	while(i<=j)
    	{
    		long int k=i*i+j*j;

    		if(k<c)
    			i++;
    		else if(k>c)
    			j--;
    		else 
    			return true;
    	}    
    	return false;
        
    }
};