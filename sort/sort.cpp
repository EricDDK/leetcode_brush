// https://blog.csdn.net/nrsc272420199/article/details/82587933
int quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x)
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] <= x)
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1);
		quick_sort(s, i + 1, r);
	}
	return 0;
}

// https://blog.csdn.net/otuhacker/article/details/10366563
void quick_sort(ListNode* begin, ListNode* end)
{
	if (!begin || !end || begin == end)
		return;
	ListNode* first = begin;
	ListNode* second = first->next;
	int tmp = first->val;
	while (second != end->next && second != NULL)
	{
		if (second->val < tmp)
		{
			first = first->next;
			std::swap(first->val, second->val);
		}
		second = second->next;
	}
	std::swap(begin->val, first->val);
	quick_sort(begin, first);
	quick_sort(first->next, end);
}