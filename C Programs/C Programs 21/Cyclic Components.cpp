#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 2e5 + 15, UNMARKED = -1;
vector <int> graph[MAX_N];
vector <int> component[MAX_N];
int component_no[MAX_N];

void dfs_and_mark_component(int v, int no)
{
    component[no].push_back(v);
    component_no[v] = no;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(component_no[child] == UNMARKED)
            dfs_and_mark_component(child, no);
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(component_no, UNMARKED, sizeof(component_no));

    int no_of_components = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(component_no[i] == UNMARKED)
            dfs_and_mark_component(i, no_of_components++);
    }

    int no_of_cycles = 0;

    for(int i = 0; i < no_of_components; i++)
    {
        int is_cycle = true;

        for(int j = 0; j < component[i].size(); j++)
        {
            int v = component[i][j];

            if(graph[v].size() != 2)
            {
                is_cycle = false;
            }
        }

        no_of_cycles += (is_cycle == true);
    }

    printf("%d\n", no_of_cycles);
    return 0;
}
