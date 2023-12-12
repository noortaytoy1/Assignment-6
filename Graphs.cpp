// FILE: graphs.cpp
// Graph Library Implementation File for Asn 6

#include <fstream>		// For reading file from disk
#include <iostream>
#include <string>		// For file name
#include <iomanip>	// Deinition of an Edge
#include <sstream>
using namespace std;
#include <vector>
#include <stack>
// Constructor
Graphs::Graphs()
{
	E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const
{
	return char(s+65);
}

// Get Graph from text File (file name is stored in string fname)
// Graph is stored in adjacency matrix
void Graphs::getGraph(string fname)		
{
   // Local data ...
	weightType wi;
	ifstream source;
	source.open(fname.c_str());
	string linesize; 
	while(getline(source,linesize))
	{
		V++;
	}
	source.close();
	
	ifstream infile(fname);
	
	int i=0;
	int j=0;
	string line;
	int weight;
	while(getline(infile,line))
	{
		istringstream iss(line);
		while(iss >> weight)
		{
			AdjMatrix[i][j]=weight;
			j++;
		}
		i++;
		j=0;
	}

	
	
}

// Display Adjacency Matrix
void Graphs::dispGraph() const
{
	ofstream outfile("TestG.txt");

	int i,j;
	cout<<"Adjacency Matrix\n";
	for(i=0; i<V; i++)
	{      for(j=0; j<V; j++){
			cout<< setw(3)<< AdjMatrix[i][j] << " ";
			outfile<<AdjMatrix[i][j] << " ";
	}
		cout<< endl;
		outfile<<endl;
	}
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[]. 
void Graphs::getEdges()			
{
	int r , c;
	int i = 0;
	weightType weight;

	// Only examine weights above the diagonal 
	for (r = 0; r <= V-2; r++)
		for (c = r+1; c <= V-1; c++)
		{
			weight = AdjMatrix[r][c];
			if (weight > 0)
			{
				// save (r,c,weight) in edges[i]
				edges[i].u = r;
				edges[i].v = c;
				edges[i].w = weight;
				i++;
			}

		}
	E = i;		// Number of non-zero edges
	
}

// Get number of vertices (V)	
int Graphs::No_of_Verices() const 				
{
	return V;
}

// Get Number of Non-zero edges (E)
int Graphs::No_of_Edges() const 					
{
	return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const 			
{
	cout << Vname(e.u) << " " << Vname(e.v) << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::dispEdges() const
{
	cout<<"Graph Edges\n";
	for (int i = 0; i < E; i++) 
		printEdge(edges[i]);
}

// Shortest paths from node s
// uses Dijkstra's Algorithm
void Graphs::shPath(int s)
{
	int distance[V];
	for(int i=0;i<V;i++)
	{
		distance[i]=4444444444444444444;
	}
	vector<bool>visited(V,false);
	int checked_index=0;
	int min_index;
	distance[s]=0;
	visited[s]=true;
	int i=s;

for(int i=s;i<V-1;i++)
 {
	long int min_value=99999999999;
	for(int j=0;j<V;j++)
	{
		if(visited[j]|| i==j)
		{
			continue;
		}
		else
		{
			if(i!=j)
			{
				if(AdjMatrix[i][j]!=0){
				if(distance[i]+ AdjMatrix[i][j] < distance[j])
				distance[j]=distance[i]+AdjMatrix[i][j];
				}
				else
				continue;
			}
			if(AdjMatrix[i][j]<=min_value)
			{
				min_value=AdjMatrix[i][j];
				min_index=j;
				checked_index=i;
			}
			}
		}
		cout<<"The min value is "<<min_value << " and it is between " << i << " and " << min_index<<endl;
      visited[checked_index]=true;
	  cout<<endl;
 }
 for(int i=0;i<V;i++)
 {
	if(distance[i]==4444444444444444444)
	cout<<"There's no direct edge path in this index" << i;
	else
	cout<<distance[i] << " " <<endl;
 }
 }



// Print path (vertex names) from source (s) to destination (i)
void Graphs::printPath(int s, int i) const
{
	cout<< Vname(s) << " " << Vname(i)<<" ";
}

void Graphs::visit(int k) {
	order++;
    val[k] = order;
    cout << k << " "; // print visited node
    for (int t = 0; t < V; ++t) {
        if (AdjMatrix[k][t] != 0 && val[t] == -1) {
            visit(t);
        }
    }
}

void Graphs::DFS() {
    // Initialize all to unseen
    for (int k = 0; k < V; ++k) {
        val[k] = -1;
    }

    // Follow Nodes in Depth
    for (int k = 0; k < V; ++k) {
        if (val[k] == -1) {
            visit(k); //recursion and call the visit function
        }
    }
}
