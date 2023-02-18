/****
* COURTESY OF JoselitoTp - UCBCBA - BOLIVIA
****/
#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define punteria(a) cout<<setprecision(a)<<endl
#define print(a) cout<<a<<endl;
#define input(a) cin.ignore();getline(cin,a);

using namespace std;


bool basta;

void dfs(int indice, vector<int> &  papa, vector<bool>  & mama, int dad, vector<int> adj[], int like){
    if(mama[indice] or basta) return; 

    if(indice == like) {
        basta = true; 
        papa[like] = dad; 
        return; 
    }

    papa[indice] = dad; 
    mama[indice] = true;
    dad = indice;
    for(auto i: adj[indice]){
        dfs(i, papa, mama,  dad, adj, like); 
    }

}

string generate1(int valMat,int j,int m){
    if(valMat==0 &&j==m-1)return "|";
    else if(valMat==0) return " "; 
    else if(j==m-1|| valMat==1 ||valMat==3)return "|";
    else return " "; 
}

string generate2(int valMat,int j,int m){
    if( valMat==1 || valMat==0)return "   ";
    else return "---"; 
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, m, a, b, o, p; 
    int cont = 1;
    while(true){

        cin>>n>>m>>a>>b>>o>>p; 

        if(n == 0) break; 
        short finale = (o - 1)* m + p-1, inicio = (a-1) * m +  b-1; 

        //print(finale)
        short mat[n][m];
        vector<bool> marcados(n * m, 0); 
        vector<int> papa(n*m), ruta;
        papa[inicio] = -1;
        basta = false; 
        cout<<"Maze "<<cont<<endl<<endl;
         cont++;
        string s="---";
        cout<<"+";
        for(int i=0;i<m;i++){
            cout<<s;
            if(i!=m-1)cout<<"+";
         }
        cout<<"+";

         cout<<endl;
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                cin>>mat[i][j]; 
            }
        }
        int nodo = 0;
        vector<int> adj[n*m]; 
        int cont = 0;
        for(int i=0; i<n; i++){ 
            for(int j=0; j<m; j++){
                if(j != 0){
                    if(mat[i][j-1] != 1 and mat[i][j-1] != 3) adj[nodo].push_back(nodo-1);  
                }
                
                if(i != 0) if(mat[i-1][j] != 2 and mat[i-1][j] != 3) adj[nodo].push_back(nodo-m); 

                if(j != m-1) if(mat[i][j] != 1 and mat[i][j] != 3) adj[nodo].push_back(nodo +1); 

                if(i != n-1) if(mat[i][j] != 2 and mat[i][j] != 3) adj[nodo].push_back(nodo + m); 
                nodo++;
            }

        }
        int sebas=0;
        dfs(inicio, papa, marcados, -1, adj, finale);
        int actual = finale;
        while(actual != -1){
            ruta.push_back(actual); 
            actual = papa[actual]; 
        }


        int signos[n][m]; 

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(marcados[i*m + j]){ signos[i][j] = -1; 
                }else signos[i][j] = 0; 
            }
        }
        int paso = 1;
        for(int i = ruta.size()-1; i>=0; i--){
            signos[ruta[i]/m][ruta[i]%m] = paso;
            paso ++; 
        }
        
        for(int i=0; i<n; i++){
            cout<<"|";
            stringstream s1,s2;
            for(int j=0; j<m; j++){
                stringstream ss;
                    ss<<signos[i][j];

                if(signos[i][j]==-1 ){
                    s1<<"???"<<generate1(mat[i][j],j,m);
                    s2<<generate2(mat[i][j],j,m);
                }
                else if(signos[i][j]==0){
                    s1<<"   "<<generate1(mat[i][j],j,m);
                    s2<<generate2(mat[i][j],j,m);
                }
                else if(signos[i][j]>0){
                    if(signos[i][j]<10)s1<<"  ";
                    else if(signos[i][j]>9) s1<<" ";
                    s1<<signos[i][j];
                    if(signos[i][j]<99)s1<<generate1(mat[i][j],j,m);
                    s2<<generate2(mat[i][j],j,m);
                }
                s2<<"+";
                
            }
            
            cout<<s1.str()<<endl;
            if(i!=n-1)cout<<"+"<<s2.str()<<endl; 
        }
         cout<<"+";
        for(int i=0;i<m;i++){
            cout<<s;
            if(i!=m-1)cout<<"+";
         }
         cout<<"+";
         cout<<endl;
         cout<<endl<<endl;

    }


    

    return 0;
}