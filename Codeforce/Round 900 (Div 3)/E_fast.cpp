#ifndef _GLIBCXX_NO_ASSERT
  #include <cassert>
  #endif
  #include <cctype>
  #include <cerrno>
  #include <cfloat>
  #include <ciso646>
  #include <climits>
  #include <clocale>
  #include <cmath>
  #include <csetjmp>
  #include <csignal>
  #include <cstdarg>
  #include <cstddef>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <ctime>

  #if __cplusplus >= 201103L
  #include <ccomplex>
  #include <cfenv>
  #include <cinttypes>
  #include <cstdbool>
  #include <cstdint>
  #include <ctgmath>
  #include <cwchar>
  #include <cwctype>
  #endif

  // C++
  #include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream>
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif


 
 int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}


namespace atcoder {
 
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n),size = 1 << log;
        d = std::vector<S>(size<<1, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; update(i--)); 
    }
 
    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n && f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (!(l&1)) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l<<=1;if (f(op(sm, d[l])))sm = op(sm, d[l++]);
                }
                return l - size;
            }
            sm = op(sm, d[l++]);
        } while ((l & -l) != l);
        return _n;
    }
 

 
  private:
    int _n, size, log;
    std::vector<S> d;
    void update(int k) { d[k] = op(d[ k<<1], d[(k<<1)|1]);}
};
 
}  // namespace atcoder
 
using namespace std;
using namespace atcoder;
 
int op(int a,int b){
  return (a&b);
}
int e(){
  return ((1<<30)-1);
}
 
int K;
bool f(int x){
  return (x>=K);
}
 
void  solve(){

    int n; cin >> n; 
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    segtree<int,op,e> seg(a);
    int q;
    cin >> q;
    while(q--){
      
      int l; cin >> l >> K;
      if(a[--l]<K){cout << "-1 ";}
      else{
        cout << seg.max_right<f>(l)<<" ";
      }
    }
    cout << "\n";
  
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int tc =1; cin>>tc;
    while (tc--) 
        solve();
    return 0;
}


