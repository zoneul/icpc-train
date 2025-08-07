#include <bits/stdc++.h>
using namespace std;

int n_c, n_a, inst_rate;
double t_hit, t_miss;

double total_time = 0.0;
int co=0;
int n_hit = 0, n_miss = 0;
// name, frequency, first access time

deque<tuple<string,int,double>> disk;
deque<tuple<string,int,double>> cache;

tuple<string,int,double> move_from_disk(string inst)
{
    cout << "MOVE " << inst << " FROM DISK" << endl;
    auto it = find_if(disk.begin(), disk.end(), [&](const auto& item) {
        return get<0>(item) == inst;
    });

    tuple<string,int,double> tmp = {inst, 0, -1};
    if(it != disk.end()) 
    {
        tmp = *it; // Copy the item
        disk.erase(it); // Remove from disk
    }

    return tmp;
}

void get(string inst)
{
    // See if the instruction is in cache
    auto target = find_if(cache.begin(), cache.end(), [&](const auto& item) {
        return get<0>(item) == inst;
    });
        
    cout << "------------------------------" << endl;
    
    bool hit = false;
    if(target != cache.end()) // Hit
    {
        hit = true;
        n_hit++;
        // Move to front
        auto tmp = *target;
        cache.erase(target);
        cache.push_front(tmp); // Add to front
    }
    else // Miss
    {
        n_miss++;
        tuple<string,int,double> cmd = move_from_disk(inst);

        // Add to cache
        if(cache.size() == n_c)
        {
            cout << "MOVE " << get<0>(cache.back()) << " TO DISK" << endl;
            disk.push_back(cache.back());
            cache.pop_back();
        }
        cout << "PUT " << inst << endl;
        cache.push_front(cmd);
    }
    
    cout << "GET (" << (hit? "HIT" : "MISS") << ") " << inst << endl;
    if(get<2>(cache.front()) < 0) // First access
    {
        get<2>(cache.front()) = total_time;
        cout << fixed << setprecision(3) << "FIRST ACCESS : " << get<2>(cache.front()) << "s" << endl;
    }
    get<1>(cache.front())++; // Increment frequency
}

void report()
{
    cout << "==============================" << endl << "(REPORT)" << endl << "LRU List : ";
    for(const auto& item: cache) cout << get<0>(item) << " <- ";
    cout << "NULL" << endl << "Disk List : ";
    for(const auto& item: disk) cout << get<0>(item) << " <- ";
    cout << "NULL" << endl;

    total_time += n_hit * t_hit + n_miss * t_miss;

    cout << fixed << setprecision(3) << "Total Time : " << total_time << "s" << endl;
    cout << "CacheHit : " << n_hit << endl;
    cout << "CacheMiss : " << n_miss << endl;
}

void auto_relace()
{
    cout << "==============================" << endl << "(AUTO REPLACEMENT)" << endl;
            
        // Min freq over time from cache
        auto min_cache = min_element(cache.begin(), cache.end(), [](const auto& a, const auto& b) {
            if(total_time - get<2>(a) <= 0) return false;
            if(total_time - get<2>(b) <= 0) return true;
            return (get<1>(a) / (total_time - get<2>(a))) < (get<1>(b) / (total_time - get<2>(b)));
        });
        // Max freq over time from disk
        auto max_disk = max_element(disk.begin(), disk.end(), [&](const auto& a, const auto& b) {
            if(total_time - get<2>(a) <= 0) return false;
            if(total_time - get<2>(b) <= 0) return true;
            return (get<1>(a) / (total_time - get<2>(a))) < (get<1>(b) / (total_time - get<2>(b)));
        });

        
        if(min_cache == cache.end() || total_time - get<2>(*min_cache) <= 0 || 
            max_disk == disk.end() || total_time - get<2>(*max_disk) <= 0) cout << "NO REPLACEMENT" << endl;
        else
        {
            double mi = get<1>(*min_cache) / (total_time - get<2>(*min_cache));
            double ma = get<1>(*max_disk) / (total_time - get<2>(*max_disk));
            cout << get<0>(*min_cache) << "(" << mi << ") - Cache" << endl;
            cout << get<0>(*max_disk) << "(" << ma << ") - Disk" << endl;

            if(ma <= mi) cout << "Cache is better" << endl;
            else 
            {
                auto tmp_min = *min_cache;
                auto tmp_max = *max_disk;      
                disk.erase(max_disk);
                cache.erase(min_cache);

                cout << "MOVE " << get<0>(tmp_max) << " FROM DISK" << endl;
                cache.push_front(tmp_max);
                cout << "MOVE " << get<0>(tmp_min) << " TO DISK" << endl;
                disk.push_back(tmp_min);
            }
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

    vector<tuple<string,int,double>> inst_list(n_a);
    for(auto& [name, params, cost]: inst_list) cin >> name >> params >> cost;

    
    string s;
    cin.ignore();
    while(getline(cin, s))
    {
        stringstream ss(s);
        string inst_name;
        ss >> inst_name;

        tuple<string,int,double> inst = {"", 0, 0.0};
        for(auto& [name, params, cost]: inst_list)
        {
            if(name == inst_name)
            {
                inst = {name, params, cost};
                break;
            }
        }

        if(get<0>(inst) == "")
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        
        get(inst_name);
        co++;

        if(co % inst_rate == 0 && co > 0) auto_relace();
        
        if(inst_name == "HALT") 
        {
            total_time += get<2>(inst);
            break;
        }
        else if(inst_name == "REBOOT")
        {
            cout << "==============================" << endl << "(REBOOT)" << endl;
            for(auto& [name, f, t]: cache) cout << "MOVE " << name << " TO DISK" << endl;
            for(auto itr = cache.rbegin(); itr!=cache.rend(); itr++) cout << "RESTORE " << get<0>(*itr) << " FROM DISK" << endl;
        }

        string param_name;
        while(ss >> param_name)
        {
            if(param_name.back() == ',') param_name.pop_back();
            get(param_name);
        }
        total_time += get<2>(inst);
    }
    report();
}