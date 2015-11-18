#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void trim_string(string &s) {
    s.erase(0, s.find_first_not_of(" \n\r\t"));
    s.erase(s.find_last_not_of(" \n\r\t")+1);
}

template <typename Node>
struct graph {
    unordered_set<Node> nodes;
    unordered_map<Node, unordered_set<Node>> edges;

    void add_node(const Node &i) {
	nodes.insert(i);
    }

    void add_edge(const Node &i, const Node &j) {
	edges[i].insert(j);
    }
};

template <typename Node>
void read_makefile(const string& filename, graph<Node>& g, bool directed) {
    ifstream infile(filename);
    string line;
    Node i, j;
    while (getline(infile, line)) {
	size_t split = line.find(':');
	if (split == string::npos) {
	    continue;
	}

	string target  = line.substr(0, split);
	string sources = line.substr(split + 1, line.size() - split);

	trim_string(target);
	trim_string(sources);

	// TODO: Add node
	istringstream iss(target);
	iss >> i;
	g.add_node(i);	

	stringstream ss(sources);
	string source;
	while (ss >> source) {
	    // TODO: Add edges(s)
	    istringstream iss(source);
	    iss >> j;
	    g.add_edge(i,j);
	}
    }
}

template <typename Node>
void find_dependencies(const graph<Node> &g, const Node &target, vector<string> &dependencies) {
    // TODO: Perform graph traversal to find dependencies
    stack<Node> frontier;
    unordered_set<Node> marked;
    frontier.push(target);
    while(frontier.size() > 0) {
	Node u = frontier.top();
	frontier.pop();
	auto got = g.edges.find(u);
	marked.insert(u);
	// add u to dependecies
	if(u != target){
		dependencies.push_back(u);
	}
	if(got != g.edges.end()) {
	    for(Node v : got->second) {
		if(marked.count(v) == 0) frontier.push(v);
	    }
	}
    }
}

int main (int argc, char *argv[]) {
    graph<string> g;
    vector<string> dependencies;

    if (argc != 3) {
    	cerr << "usage: " << argv[0] << " Makefile target" << endl;
    	return 1;
    }

    string path(argv[1]);
    string target(argv[2]);

    read_makefile(path, g, true);
    find_dependencies(g, target, dependencies);

    sort(dependencies.begin(), dependencies.end());
    cout << "There are " << dependencies.size() << " dependencies for target " << target << ":" << endl;
    for (auto &dependency : dependencies)
    	cout << '\t' << dependency << endl;

    return 0;
}
