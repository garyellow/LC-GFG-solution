class Solution {
public:
    string pushDominoes(string dominoes) {
        int i = -1, j = 0;
        
        while(++i < dominoes.size())
        {
            if(dominoes[i] == 'R')
            {
                j = i;
                while(++i < dominoes.size())
                {
                    if(dominoes[i] == 'L')
                    {
                        int temp = i;
                        
                        while(j < temp)
                        {
                            dominoes[j++] = 'R';
                            dominoes[temp--] = 'L';
                        }
                        
                        j = i + 1;
                        break;
                    }
                    else if(dominoes[i] == 'R')
                        while(j < i)
                            dominoes[j++] = 'R';
                }
                
                if(i == dominoes.size())
                    while(j < i)
                        dominoes[j++] = 'R';
            }
            else if(dominoes[i] == 'L')
                while(j <= i)
                    dominoes[j++] = 'L';
        }
        
        return dominoes;
    }
};