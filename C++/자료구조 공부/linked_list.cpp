template <typename Type>
class Node
{
	private:
		Type element;
		Node *next_node;
		Node *prev_node;
		
	public:
		Node(Type n = 0, Node *nn = 0, Node *pn = 0) : element(n), next_node(nn), prev_node(pn) {	}
		
		Type retrieve() const
		{
			return element;
		}
		
		
		Node *next() const
		{
			return next_node;
		}
		
		
		Node *prev() const
		{
			return prev_node;
		}
		
		friend class List;
};


template <typename Type>
class List
{
	private:
		Node *list_head;
	
	public:
		List() : list_head(0) { }
		
		bool empty() const
		{
			return (list_head == 0);
		}
		
		
		Type front() const
		{
			if(!empty())
				return list_head->retrieve();
		}
		
		
		Node *head() const
		{
			return list_head;
		}
		
		
		bool member(Type a)
		{
		}
		
		
		void push_front(Type n)
		{
			list_head = new Node(n, list_head, 0);
		}
		
		
		Type pop_front() 
		{
			if(!empty)
			{
				Type e = front();
				Node *ptr = list_head;
				list_head = list_head->next();
				delete ptr;
				return e;
			}
		}
		
		
		int count(int c) const
		{
			for(Node *ptr = head(); ptr != 0; ptr = ptr->next())
			{
				if(ptr->retrieve() == n)
					return 1;
			}
			
			return 0;
		}
};


int main()
{
	return 0;
}
