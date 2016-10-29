#include <iostream> // std::cout, cin, cerr, clog
#include <cstddef> // std::size_t

namespace DataStructures
{
	namespace CircularLinkedList
	{
		template<class T>
		class Node
		{
			public:
				typedef T value_type;
				typedef value_type* pointer;
				typedef value_type& reference;
				typedef Node<T> node_type;
				typedef node_type* node_pointer;
				typedef node_type& node_reference;
				typedef std::ptrdiff_t difference_type;

				Node(void)
					: next_node(this), back_node(this)
				{}
				Node(value_type v)
					: node_value(v), next_node(this), back_node(this)
				{}
				Node(const node_reference next, const node_reference back)
					: next_node(next), back_node(back)
				{}
				Node(value_type v, const node_reference next, const node_reference back)
					: node_value(v),
						next_node(next),
						back_node(back)
				{}
				Node(const node_reference copy)
					: node_value(copy.node_value),
						next_node(copy.next_node),
						back_node(copy.back_node)
				{}
				virtual ~Node(void)
				{}

				// Implicit casts between Node<T> and T
				operator value_type(void)
				{
					return this->node_value;
				}
				node_reference operator=(const node_reference other)
				{
					this->bad_replace(other);
					return *this;
				}

				node_pointer next(void)
				{
					return this->next_node;
				}
				node_pointer back(void)
				{
					return this->back_node;
				}

				reference value(void)
				{
					return this->node_value;
				}

				void insert_next(node_pointer next)
				{
					next->next_node = this->next_node;
					next->back_node = this;
					this->next_node->back_node = next;
					this->next_node = next;
				}
				void insert_back(node_pointer back)
				{
					back->next_node = this;
					back->back_node = this->back_node;
					this->back_node->next_node = back;
					this->back_node = back;
				}
				void replace(node_reference other)
				{
					other.next = this->next_node;
					other.back = this->back_node;
					this->next_node->back_node = &other;
					this->back_node->next_node = &other;
					this->next_node = this;
					this->back_node = this;
				}
				void bad_replace(const node_reference other)
				{
					this->next_node = other.next_node;
					this->back_node = other.back_node;
					this->node_value = other.node_value;
				}
				void remove(void)
				{
					this->back_node->next_node = this->next_node;
					this->next_node->back_node = this->back_node;
					this->next_node = this;
					this->back_node = this;
				}
				void swap_next(void)
				{
					this->next_node->back_node = this->back_node;
					this->back_node->next_node = this->next_node;
					this->next_node->next_node->back_node = this;
					this->next_node->next_node = this;
					this->back_node = this->next_node;
					this->next_node = this->next_node->next_node;
				}
				void swap_back(void)
				{
					this->back_node->next_node = this->next_node;
					this->next_node->back_node = this->back_node;
					this->back_node->back_node->next_node = this;
					this->back_node->back_node = this;
					this->next_node = this->back_node;
					this->back_node = this->back_node->back_node;
				}
			private:
				value_type node_value;
				node_pointer next_node;
				node_pointer back_node;
		};

		template<class T>
		typename Node<T>::node_pointer operator+(
			const typename Node<T>::node_reference self,
			typename Node<T>::difference_type len
		)
		{
			typename Node<T>::node_pointer ptr = &self;

			while(len-- > 0)
			{
				ptr = ptr->next();
			}

			return ptr;
		}
		template<class T>
		typename Node<T>::node_pointer operator-(
			const typename Node<T>::node_reference self,
			typename Node<T>::difference_type len
		)
		{
			typename Node<T>::node_pointer ptr = &self;

			while(len-- > 0)
			{
				ptr = ptr->back();
			}

			return ptr;
		}

		template<class T, class nodeT = Node<T> >
		class List
		{
			public:
				typedef nodeT node_type;
				typedef T value_type;
				typedef value_type* pointer;
				typedef value_type& reference;
				typedef node_type* node_pointer;
				typedef node_type& node_reference;
				typedef std::ptrdiff_t difference_type;
				typedef List<T> list_type;
				typedef list_type* list_pointer;
				typedef list_type& list_reference;
				typedef std::size_t size_type;

				List(void)
					: list_size(0),
						list_head(new node_type)
				{}
				List(const list_reference copy)
					: list_size(0),
						list_head(new node_type)
				{
					for(size_type i = 0; i < copy.list_size; i++)
					{
						this->push_back(copy[i]);
					}
				}
				virtual ~List(void)
				{
					while(this->list_size > 0)
						this->pop_back();
					delete this->list_head;
				}

				value_type operator[](size_type i)
				{
					return this->at(i);
				}
				list_reference operator=(const list_reference other)
				{
					if(this == *other)
						return *this;
					this->list_size = 0;
					for(size_type i = 0; i < other.size(); i++)
					{
						this->push_back(other[i]);
					}
					return *this;
				}

				void push_front(value_type val)
				{
					this->list_size++;
					this->list_head->insert_next(new node_type(val));
				}
				void push_back(value_type val)
				{
					this->list_size++;
					this->list_head->insert_back(new node_type(val));
				}
				void insert_next(value_type val)
				{
					this->push_front(val);
				}
				void insert_back(value_type val)
				{
					this->push_back(val);
				}
				value_type pop_front(void)
				{
					this->list_size--;
					node_pointer ptr = this->list_head->next();
					ptr->remove();
					value_type val = ptr->value();
					delete ptr;
					return val;
				}
				value_type pop_back(void)
				{
					this->list_size--;
					node_pointer ptr = this->list_head->back();
					ptr->remove();
					value_type val = ptr->value();
					delete ptr;
					return val;
				}
				size_type size(void)
				{
					return this->list_size;
				}
				value_type at(size_type i)
				{
					node_pointer ptr = this->list_head->next();
					for(size_type j = 0; j < i; j++)
					{
						ptr = ptr->next();
						if(ptr == this->list_head)
						{
							return value_type();
						}
					}
					return ptr->value();
				}
				node_pointer begin(void)
				{
					return this->list_head->next();
				}
				node_pointer end(void)
				{
					return this->list_head->back();
				}
				node_pointer head(void)
				{
					return this->list_head;
				}
			private:
				size_type list_size;
				node_pointer list_head;
		};
	}
}

int main(int argc, char** argv)
{
	DataStructures::CircularLinkedList::List<int> mylist;

	for(std::size_t i = 0; i < 10; i++)
		mylist.push_back(i);

	std::cout << "mylist have a length of " << mylist.size() << std::endl;

	for(std::size_t i = 0; i < mylist.size(); i++)
	{
		std::cout << "[" << mylist[i] << "]";
	}

	std::cout << std::endl
		<< "next of the last element: "
		<< mylist.end()->next()->value()
		<< std::endl
		<< "head: "
		<< mylist.head()->value()
		<< std::endl;

	return 0;
}
