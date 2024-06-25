# include "PmergeMe.hpp"

unsigned long long	ft_atoull(std::string & str)
{
	int	i = 0;
	unsigned long long res = 0;
	if (str.size() == 0)
		throw std::invalid_argument("Empty argument");
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			throw std::invalid_argument("Only positive integer");
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > ULLONG_MAX / 10)
			|| (res == ULLONG_MAX / 10 && (str[i] - 48) >  static_cast<int>(ULLONG_MAX % 10)))
			throw std::out_of_range("Overflow");
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		throw std::invalid_argument(std::string(1, str[i]) + " invalid argument");
	return res;
}




// ---------------------------------------------//


//					DEQUE


// ---------------------------------------------//




void	ft_merge_sort_max_element_deque(std::deque<unsigned long long> *d, d_it start, d_it end,\
	 std::deque<unsigned long long> *max_elements)
{
	int range = std::distance(start, end);

	std::cout << "nouvelle list" << std::endl;
	ft_print_T(start, end);
	if (range > 2)
	{
		d_it median = start + range / 2;
		if (range == 3)
		{
			std::cout << "median++" << std::endl;
			median++;
		}
		ft_merge_sort_max_element_deque(d, start, median, max_elements);
		ft_merge_sort_max_element_deque(d, median, end, max_elements);
	}

	if (range == 2)
	{
		std::cout << "start = " << *start << " end = " << *(end - 1) << std::endl;
		if (*start > *(end - 1))
		{
			// max_elements->push_front(*start); // insert recursive
			ft_binary_search_insertion_elements_deque(max_elements, *start, static_cast<int>(max_elements->size() / 2));
			d->erase(start);
			std::cout << "plus grand" << std::endl;
		}
		else
		{
			// max_elements->push_front(*(end - 1)); // insert recursive
			ft_binary_search_insertion_elements_deque(max_elements, *(end - 1), static_cast<int>(max_elements->size() / 2));
			d->erase(end - 1);
			std::cout << "plus petit" << std::endl;
		}
	}
}

bool	ft_binary_search_insertion_elements_deque(std::deque<unsigned long long> *me, unsigned long long val, int median)
{
	// creer une partie left et right de me
	std::deque<unsigned long long> left;
	std::deque<unsigned long long> right;

	if (me->empty())
	{
		std::cout << "free insert" << std::endl;
		me->push_back(val);
		return true;
	}
	std::cout << "nouvelle appel" << std::endl;

	if (me->size() > 1)
	{
		std::cout << "me:" << std::endl;
		ft_print_T(me->begin(), me->end());
		std::cout << "median = " << median << std::endl;
		left.insert(left.begin(), me->begin(), me->begin() + median);
		std::cout << "left" << std::endl;
		ft_print_T(left.begin(), left.end());

		right.insert(right.begin(), me->begin() + median, me->end());
		std::cout << "right" << std::endl;
		ft_print_T(right.begin(), right.end());

		std::cout << "value = " << val << std::endl;
	// repeter jusqua ce que la taille soit de 1
		// comparer a la valeur median si elle est supp ou inf
		std::cout << "median = " << median << std::endl;
		std::cout << "size de me = " << me->size() << std::endl;

		std::cout << "recursive check " << val << " > " << *(me->begin() + median) << " ?" << std::endl;
		// si elle est supp refaire avec la median right
		if (val > *(me->begin() + median))
		{
			// si la fonction a trouver et a inserer la valeur clear me et merge left et right puis return
			std::cout << "recursive avec right" << std::endl;
			if (ft_binary_search_insertion_elements_deque(&right, val, right.size() / 2))
			{
				me->clear();
				me->insert(me->begin(), left.begin(), left.end());
				me->insert(me->end(), right.begin(), right.end());
				return true;
			}
			// le return permet de ne pas continuer si on a trouver ou insert la valeur
			// sinon elle sera reinsserre ailleur
		}
		// sinon avec la median left
		else
		{
			std::cout << "recursive avec left" << std::endl;
			if (ft_binary_search_insertion_elements_deque(&left, val, right.size() / 2))
			{
				me->clear();
				me->insert(me->begin(), left.begin(), left.end());
				me->insert(me->end(), right.begin(), right.end());
				return true;
			}
			// std::cout << "taile de me = " << me->size() / 2 << std::endl;
			ft_binary_search_insertion_elements_deque(&left, val, left.size() / 2);
		}
	}
	std::cout << "ME AVANT INSERTION ? " << std::endl;
	ft_print_T(me->begin(), me->end());
	std::cout << "j'insert" << std::endl;
	std::cout << "median d'insertion = " << median << std::endl;
	std::cout << val << " > " << *(me->begin()) << " ?" << std::endl;

	if (val > *(me->begin()))
	{
		std::cout << "insert + 1" << std::endl;
		me->insert(me->begin() + 1, val);
		return true;
	}
	else
	{
		std::cout << "insert" << std::endl;
		me->insert(me->begin(), val);
		return true;
	}
	return false;
}

// insert un a un les elements de d dans max_elements par dichotomie
void	ft_insert_in_max_elements_deque(std::deque<unsigned long long> *d, std::deque<unsigned long long> *max_elements)
{
	// prendre le premier element de d et l'envoyer dans bsi
	std::cout << "QWERQWERQWERWEQEQWRQWWEQ avant insertion dans me" << std::endl;
	if (d->size() != 0)
		ft_print_T(d->begin(), d->end());
	ft_print_T(max_elements->begin(), max_elements->end());
	if (d->size() != 0)
	{

		std::cout << RED << "avant insertion:" << RESET << std::endl;

		std::cout << "d:" << std::endl;
		ft_print_T(d->begin(), d->end());

		std::cout << "max element" << std::endl;
		ft_print_T(max_elements->begin(), max_elements->end());

		ft_binary_search_insertion_elements_deque(max_elements, *(d->begin()), max_elements->size() / 2);

		std::cout << RED << "apres insertion:" << RESET << std::endl;

		std::cout << "d:" << std::endl;
		ft_print_T(d->begin(), d->end());
		
		std::cout << "max element" << std::endl;
		ft_print_T(max_elements->begin(), max_elements->end());


		// supprimer le premier element de d
		d->erase(d->begin());

		// refaire jusqu'a que d soit vide
		ft_insert_in_max_elements_deque(d, max_elements);
	}

	// une fois que d est vide copier me dans d
	else
	{
		d->clear();
		d->insert(d->begin(), max_elements->begin(), max_elements->end());
		// supprimer me
		max_elements->clear();
	}
}

void	ft_FordJohnsonDeque(std::deque<unsigned long long> *d)
{
	std::deque<unsigned long long> max_elements;

	// etape 1
	ft_merge_sort_max_element_deque(d, d->begin(), d->end(), &max_elements);
	// etape 2
	ft_insert_in_max_elements_deque(d, &max_elements);

	std::cout << RED << "AFTER D:\n" << RESET;
	ft_print_T(d->begin(), d->end());
	std::cout << "ME" << std::endl;
	ft_print_T(max_elements.begin(), max_elements.end());
}



// ---------------------------------------------//


//					VECTOR


// ---------------------------------------------//





void	ft_merge_sort_max_element_vector(std::vector<unsigned long long> *v, v_it start, v_it end,\
	 std::vector<unsigned long long> *max_elements)
{
	int range = std::distance(start, end);

	std::cout << "nouvelle list" << std::endl;
	ft_print_T(start, end);
	if (range > 2)
	{
		v_it median = start + range / 2;
		if (range == 3)
		{
			std::cout << "median++" << std::endl;
			median++;
		}
		ft_merge_sort_max_element_vector(v, start, median, max_elements);
		ft_merge_sort_max_element_vector(v, median, end, max_elements);
	}

	if (range == 2)
	{
		std::cout << "start = " << *start << " end = " << *(end - 1) << std::endl;
		if (*start > *(end - 1))
		{
			// max_elements->push_front(*start); // insert recursive
			ft_binary_search_insertion_elements_vector(max_elements, *start, static_cast<int>(max_elements->size() / 2));
			start = v->erase(start);
			std::cout << "plus grand" << std::endl;
		}
		else
		{
			// max_elements->push_front(*(end - 1)); // insert recursive
			ft_binary_search_insertion_elements_vector(max_elements, *(end - 1), static_cast<int>(max_elements->size() / 2));
			std::cout << "?? end - 1 = " << *(end - 1) << std::endl;
			ft_print_T(v->begin(), v->end());
			// end = v->erase(end - 1);
			std::cout << "plus petit" << std::endl;
		}
	}
}

bool	ft_binary_search_insertion_elements_vector(std::vector<unsigned long long> *me, unsigned long long val, int median)
{
	// creer une partie left et right de me
	std::vector<unsigned long long> left;
	std::vector<unsigned long long> right;

	if (me->empty())
	{
		std::cout << "free insert" << std::endl;
		me->push_back(val);
		return true;
	}
	std::cout << "nouvelle appel" << std::endl;

	if (me->size() > 1)
	{
		std::cout << "me:" << std::endl;
		ft_print_T(me->begin(), me->end());
		std::cout << "median = " << median << std::endl;
		left.insert(left.begin(), me->begin(), me->begin() + median);
		std::cout << "left" << std::endl;
		ft_print_T(left.begin(), left.end());

		right.insert(right.begin(), me->begin() + median, me->end());
		std::cout << "right" << std::endl;
		ft_print_T(right.begin(), right.end());

		std::cout << "value = " << val << std::endl;
	// repeter jusqua ce que la taille soit de 1
		// comparer a la valeur median si elle est supp ou inf
		std::cout << "median = " << median << std::endl;
		std::cout << "size de me = " << me->size() << std::endl;

		std::cout << "recursive check " << val << " > " << *(me->begin() + median) << " ?" << std::endl;
		// si elle est supp refaire avec la median right
		if (val > *(me->begin() + median))
		{
			// si la fonction a trouver et a inserer la valeur clear me et merge left et right puis return
			std::cout << "recursive avec right" << std::endl;
			if (ft_binary_search_insertion_elements_vector(&right, val, right.size() / 2))
			{
				me->clear();
				me->insert(me->begin(), left.begin(), left.end());
				me->insert(me->end(), right.begin(), right.end());
				return true;
			}
			// le return permet de ne pas continuer si on a trouver ou insert la valeur
			// sinon elle sera reinsserre ailleur
		}
		// sinon avec la median left
		else
		{
			std::cout << "recursive avec left" << std::endl;
			if (ft_binary_search_insertion_elements_vector(&left, val, right.size() / 2))
			{
				me->clear();
				me->insert(me->begin(), left.begin(), left.end());
				me->insert(me->end(), right.begin(), right.end());
				return true;
			}
			// std::cout << "taile de me = " << me->size() / 2 << std::endl;
			ft_binary_search_insertion_elements_vector(&left, val, left.size() / 2);
		}
	}
	std::cout << "ME AVANT INSERTION ? " << std::endl;
	ft_print_T(me->begin(), me->end());
	std::cout << "j'insert" << std::endl;
	std::cout << "median d'insertion = " << median << std::endl;
	std::cout << val << " > " << *(me->begin()) << " ?" << std::endl;

	if (val > *(me->begin()))
	{
		std::cout << "insert + 1" << std::endl;
		me->insert(me->begin() + 1, val);
		return true;
	}
	else
	{
		std::cout << "insert" << std::endl;
		std::cout << "???" << *(me->begin()) << std::endl;
		me->insert(me->begin(), val);
		return true;
	}
	return false;
}


// insert un a un les elements de d dans max_elements par dichotomie
void	ft_insert_in_max_elements_vector(std::vector<unsigned long long> *v, std::vector<unsigned long long> *max_elements)
{
	// prendre le premier element de v et l'envoyer dans bsi
	std::cout << "QWERQWERQWERWEQEQWRQWWEQ avant insertion dans me" << std::endl;
	if (v->size() != 0)
		ft_print_T(v->begin(), v->end());
	ft_print_T(max_elements->begin(), max_elements->end());
	if (v->size() != 0)
	{
		std::cout << RED << "avant insertion:" << RESET << std::endl;

		std::cout << "v:" << std::endl;
		ft_print_T(v->begin(), v->end());

		std::cout << "max element" << std::endl;
		ft_print_T(max_elements->begin(), max_elements->end());

		ft_binary_search_insertion_elements_vector(max_elements, *(v->begin()), max_elements->size() / 2);
		
		std::cout << RED << "apres insertion:" << RESET << std::endl;

		std::cout << "v:" << std::endl;
		ft_print_T(v->begin(), v->end());
		
		std::cout << "max element" << std::endl;
		ft_print_T(max_elements->begin(), max_elements->end());
		
		
		// supprimer le premier element de v
		v->erase(v->begin());

		// refaire jusqu'a que v soit vide
		ft_insert_in_max_elements_vector(v, max_elements);
	}

	// une fois que v est vide copier me dans v
	else
	{
		v->clear();
		v->insert(v->begin(), max_elements->begin(), max_elements->end());
		// supprimer me
		max_elements->clear();
	}
}

void	ft_FordJohnsonVector(std::vector<unsigned long long> *v)
{
	std::vector<unsigned long long> max_elements;

	// etape 1
	ft_merge_sort_max_element_vector(v, v->begin(), v->end(), &max_elements);
	// etape 2
	ft_insert_in_max_elements_vector(v, &max_elements);

	std::cout << RED << "AFTER V:\n" << RESET;
	ft_print_T(v->begin(), v->end());
	std::cout << "ME" << std::endl;
	ft_print_T(max_elements.begin(), max_elements.end());
}