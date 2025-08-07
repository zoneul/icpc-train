#include <bits/stdc++.h>
using namespace std;

int n_c, n_a, inst_rate;
double t_hit, t_miss;

double total_time = 0.0;
int co=0;
int n_hit = 0, n_miss = 0;

class Node
{
    public:
        string data;
        int frequency;
        double first_access_time;
        Node *next, *prev;
        Node(string d) : data(d), frequency(0), first_access_time(-1), next(nullptr), prev(nullptr) {}
};

class Instruction
{
    public:
        string data;
        int params;
        double cost;
        Instruction *next, *prev;
        Instruction(string d="", int p=0, double c=0) : data(d), params(p), cost(c), next(nullptr), prev(nullptr) {}
};

template <typename NodeType>
class LinkedList
{
    public:
        NodeType *head, *tail;
        int length;

        LinkedList() : head(nullptr), tail(nullptr), length(0) {}

        void add_front(NodeType *node)
        {
            if(!head) head = tail = node;
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
            }
            length++;
        }

        void add_back(NodeType *node)
        {
            if(!tail) head = tail = node;
            else
            {
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            length++;
        }

        void remove(NodeType *node)
        {
            if(node == head) head = node->next;
            if(node == tail) tail = node->prev;
            if(node->prev) node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;

            node->next = node->prev = nullptr;
            length--;
        }

        NodeType* find(const string& data)
        {
            NodeType *cur = head;
            while(cur)
            {
                if(cur->data == data) return cur;
                cur = cur->next;
            }
            return nullptr;
        }

        NodeType* find_max()
        {
            NodeType *cur = head;
            NodeType *max_node = nullptr;
            double max_ratio = -1;

            while(cur)
            {
                double t_delta = total_time - cur->first_access_time;
                if(t_delta > 0)
                {
                    double ratio = (double)cur->frequency / t_delta;
                    if(ratio > max_ratio)
                    {
                        max_ratio = ratio;
                        max_node = cur;
                    }
                }
                cur = cur->next;
            }
            return max_node;
        }

        NodeType* find_min()
        {
            NodeType *cur = head;
            NodeType *min_node = nullptr;
            double min_ratio = 1e9+7;

            while(cur)
            {
                double t_delta = total_time - cur->first_access_time;
                if(t_delta > 0)
                {
                    double ratio = (double)cur->frequency / t_delta;
                    if(ratio < min_ratio)
                    {
                        min_ratio = ratio;
                        min_node = cur;
                    }
                }
                cur = cur->next;
            }
            return min_node;
        }

        void print()
        {
            NodeType *cur = head;
            while(cur)
            {
                cout << cur->data << " <- ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }
};

LinkedList<Node> cache, disk;

Node* move_from_disk(string inst)
{
    cout << "MOVE " << inst << " FROM DISK" << endl;
    Node* it = disk.find(inst);
    if(it)
    {
        disk.remove(it);
        return it;
    }
    return new Node(inst);
}

void get(string inst)
{
    cout << "------------------------------" << endl;
    Node* target = cache.find(inst); 
    bool hit = false;
    if(target) // Hit
    {
        hit = true;
        n_hit++;

        Node* tmp = target;
        cache.remove(target);
        cache.add_front(tmp);
    }
    else // Miss
    {
        n_miss++;
        Node* node = move_from_disk(inst);

        if(cache.length == n_c)
        {
            Node* tmp = cache.tail;
            cout << "MOVE " << tmp->data << " TO DISK" << endl;
            cache.remove(cache.tail);
            disk.add_back(tmp);
        }
        cout << "PUT " << inst << endl;
        cache.add_front(node);
    }
    
    cout << "GET (" << (hit? "HIT" : "MISS") << ") " << inst << endl;
    Node* front = cache.head;
    if(front->first_access_time < 0) // First access
    {
        front->first_access_time = total_time;
        cout << fixed << setprecision(3) << "FIRST ACCESS : " << front->first_access_time << "s" << endl;
    }
    front->frequency++;
}

void report()
{
    cout << "==============================" << endl << "(REPORT)" << endl << "LRU List : ";
    cache.print();
    cout << "Disk List : ";
    disk.print();

    total_time += n_hit * t_hit + n_miss * t_miss;
    cout << fixed << setprecision(3) << "Total Time : " << total_time << "s" << endl;
    cout << "CacheHit : " << n_hit << endl;
    cout << "CacheMiss : " << n_miss << endl;
}

void auto_relace()
{
    cout << "==============================" << endl << "(AUTO REPLACEMENT)" << endl;       
    Node* min_cache = cache.find_min();
    Node* max_disk = disk.find_max();
    if(!min_cache || !max_disk) 
    {
        cout << "NO REPLACEMENT" << endl;
        return;
    }

    double t_delta_cache = total_time - min_cache->first_access_time;
    double t_delta_disk = total_time - max_disk->first_access_time; 
    if(t_delta_cache <= 0 || t_delta_disk <= 0)
    {
        cout << "NO REPLACEMENT" << endl;
        return;
    }
    else
    {
        double mi = min_cache->frequency / t_delta_cache;
        double ma = max_disk->frequency / t_delta_disk;
        cout << min_cache->data << "(" << mi << ") - Cache" << endl;
        cout << max_disk->data << "(" << ma << ") - Disk" << endl;
        if(ma <= mi) cout << "Cache is better" << endl;
        else 
        {
            Node* tmp_min = min_cache;
            Node* tmp_max = max_disk;
            disk.remove(max_disk);
            cache.remove(min_cache);
            cout << "MOVE " << tmp_max->data << " FROM DISK" << endl;
            cache.add_front(tmp_max);
            cout << "MOVE " << tmp_min->data << " TO DISK" << endl;
            disk.add_back(tmp_min);
        }
    }
}

void reboot()
{
    cout << "==============================" << endl << "(REBOOT)" << endl;
    Node* cur = cache.head;
    while(cur)
    {
        cout << "MOVE " << cur->data << " TO DISK" << endl;
        cur = cur->next;
    }
    cur = cache.tail;
    while(cur)
    {
        cout << "RESTORE " << cur->data << " FROM DISK" << endl;
        cur = cur->prev;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n_c >> n_a >> inst_rate >> t_hit >> t_miss;
    if(n_c == 0) 
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    LinkedList<Instruction> inst_list;
    for(int i = 0; i < n_a; ++i)
    {
        string name;
        int params;
        double cost;
        cin >> name >> params >> cost;
        inst_list.add_back(new Instruction(name, params, cost));
    }
    
    string s;
    cin.ignore();
    while(getline(cin, s))
    {
        stringstream ss(s);
        string inst_name;
        ss >> inst_name;

        Instruction* inst = inst_list.find(inst_name);
        if(!inst)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        
        get(inst_name);
        co++;
        if(co % inst_rate == 0 && co > 0) auto_relace();
        
        if(inst_name == "HALT") 
        {
            total_time += inst->cost;
            break;
        }
        else if(inst_name == "REBOOT") reboot();

        string param_name;
        int co2 = inst->params;
        while(co2 && ss >> param_name)
        {
            if(param_name.back() == ',') param_name.pop_back();
            get(param_name);
            co2--;
        }
        total_time += inst->cost;
    }
    report();
}