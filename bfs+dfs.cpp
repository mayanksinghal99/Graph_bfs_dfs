#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

class adjacencyMatrix
{
public:
    map<int, bool> isVisited;

    /**
     * Adds an edge to the adjacency matrix.
     * @param u The source vertex of the edge.
     * @param v The destination vertex of the edge.
     * @param direction Specifies if the edge is directed (1) or undirected (0).
     * @param adjMatrix The adjacency matrix to which the edge is added.
     */
    void addEdge(int u, int v, bool direction, vector<vector<int>> &adjMatrix)
    {
        adjMatrix[u][v] = 1;
        if (direction == 0)
            adjMatrix[v][u] = 1;
    }

    /**
     * Prints the adjacency matrix.
     * @param adjMatrix The adjacency matrix to be printed.
     */
    void printadjMatrix(vector<vector<int>> &adjMatrix)
    {
        for (int i = 0; i < adjMatrix.size(); i++)
        {
            cout << i << " -> "
                 << "{ ";
            for (int j = 0; j < adjMatrix[i].size(); j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "}" << endl;
        }
    }

    /**
     * Performs breadth-first search (BFS) on the adjacency matrix.
     * @param src The source vertex for BFS.
     * @param adjMatrix The adjacency matrix on which BFS is performed.
     */
    void bfs(int src, vector<vector<int>> &adjMatrix)
    {
        queue<int> q;
        q.push(src);
        isVisited[src] = true;
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (int neighbour = 0; neighbour < adjMatrix[front].size(); neighbour++)
            {
                if (adjMatrix[front][neighbour] == 1 && !isVisited[neighbour])
                {
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                }
            }
        }
        isVisited.clear();
    }

    /**
     * Helper function for depth-first search (DFS).
     * @param src The current vertex in DFS.
     * @param isVisited A map to keep track of visited vertices.
     * @param adjMatrix The adjacency matrix on which DFS is performed.
     */
    void dfsHelper(int src, map<int, bool> &isVisited, vector<vector<int>> &adjMatrix)
    {
        isVisited[src] = true;
        cout << src << " ";
        for (int neighbour = 0; neighbour < adjMatrix[src].size(); neighbour++)
        {
            if (adjMatrix[src][neighbour] == 1 && !isVisited[neighbour])
                dfsHelper(neighbour, isVisited, adjMatrix);
        }
    }

    /**
     * Performs depth-first search (DFS) on the adjacency matrix.
     * @param src The source vertex for DFS.
     * @param adjMatrix The adjacency matrix on which DFS is performed.
     */
    void dfs(int src, vector<vector<int>> &adjMatrix)
    {
        dfsHelper(src, isVisited, adjMatrix);
        isVisited.clear();
    }
};

class adjacencyList
{
public:
    map<int, list<int>> adjList;
    map<int, bool> isVisited;

    /**
     * Adds an edge to the adjacency list.
     *param u The source vertex of the edge.
     * @param v The destination vertex of the edge.
     * @param direction Specifies if the edge is directed (1) or undirected (0).
     */
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
            adjList[v].push_back(u);
    }

    /**
     * Prints the adjacency list.
     */
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> "
                 << "{ ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << "}" << endl;
        }
    }

    /**
     * Performs breadth-first search (BFS) on the adjacency list.
     * @param src The source vertex for BFS.
     */
    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        isVisited[src] = true;
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (auto neighbour : adjList[front])
            {
                if (!isVisited[neighbour])
                {
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                }
            }
        }
        isVisited.clear();
    }

    /**
     * Helper function for depth-first search (DFS).
     * @param src The current vertex in DFS.
     * @param isVisited A map to keep track of visited vertices.
     */
    void dfsHelper(int src, map<int, bool> &isVisited)
    {
        isVisited[src] = true;
        cout << src << " ";
        for (auto neighbour : adjList[src])
        {
            if (!isVisited[neighbour])
                dfsHelper(neighbour, isVisited);
        }
    }

    /**
     * Performs depth-first search (DFS) on the adjacency list.
     * @param src The source vertex for DFS.
     */
    void dfs(int src)
    {
        dfsHelper(src, isVisited);
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    adjacencyMatrix matrix;
    adjacencyList list;

    int choice;
    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Add edge to adjacency matrix" << endl;
        cout << "2. Add edge to adjacency list" << endl;
        cout << "3. Print adjacency matrix" << endl;
        cout << "4. Perform BFS (adjacency matrix)" << endl;
        cout << "5. Perform DFS (adjacency matrix)" << endl;
        cout << "6. Print adjacency list" << endl;
        cout << "7. Perform BFS (adjacency list)" << endl;
        cout << "8. Perform DFS (adjacency list)" << endl;
        cout << "9. Use dummy graph input" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int u, v;
            bool direction;
            cout << "Enter the source vertex: ";
            cin >> u;
            cout << "Enter the destination vertex: ";
            cin >> v;
            cout << "Is the edge directed? (0 for undirected, 1 for directed): ";
            cin >> direction;
            matrix.addEdge(u, v, direction, adjMatrix);
            break;
        }
        case 2:
        {
            int u, v;
            bool direction;
            cout << "Enter the source vertex: ";
            cin >> u;
            cout << "Enter the destination vertex: ";
            cin >> v;
            cout << "Is the edge directed? (0 for undirected, 1 for directed): ";
            cin >> direction;
            list.addEdge(u, v, direction);
            break;
        }
        case 3:
        {
            matrix.printadjMatrix(adjMatrix);
            break;
        }
        case 4:
        {
            int src;
            cout << "Enter the source vertex for BFS (adjacency matrix): ";
            cin >> src;
            matrix.bfs(src, adjMatrix);
            break;
        }
        case 5:
        {
            int src;
            cout << "Enter the source vertex for DFS (adjacency matrix): ";
            cin >> src;
            matrix.dfs(src, adjMatrix);
            break;
        }
        case 6:
        {
            list.printAdjList();
            break;
        }
        case 7:
        {
            int src;
            cout << "Enter the source vertex for BFS (adjacency list): ";
            cin >> src;
            list.bfs(src);
            break;
        }
        case 8:
        {
            int src;
            cout << "Enter the source vertex for DFS (adjacency list): ";
            cin >> src;
            list.dfs(src);
            break;
        }
        case 9:
        {
            // Dummy graph input
            list.addEdge(0, 1, 0);
            list.addEdge(0, 2, 0);
            list.addEdge(0, 3, 0);
            list.addEdge(1, 4, 0);
            list.addEdge(1, 5, 0);
            list.addEdge(1, 9, 0);
            list.addEdge(2, 4, 0);
            list.addEdge(2, 6, 0);
            list.addEdge(2, 7, 0);
            list.addEdge(3, 6, 0);
            list.addEdge(3, 8, 0);
            cout << "Dummy graph input has been added." << endl;
            break;
        }
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 10);

    return 0;
}
