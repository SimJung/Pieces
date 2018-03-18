#include <iostream>

using namespace std;




template <typename Type>
class Simple_tree
{
	private:
		Type element;
		Simple_tree *parent_node;
		Single_list<Simple_tree *> children;
	
	public:
		Simple_tree(Type const &, Simple_tree * = 0);
		
		Type retrieve() const;
		Simple_tree *parent() const;
		int degree() const;
		bool is_root() const;
		bool is_leaf() const;
		Simple_tree *child(int n) const;
		int height() const;
		
		void insert(Type const &);
		void insert(Simple_tree *);
		void detach();
	
};


int main(void)
{
	
	return 0;
}
