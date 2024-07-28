//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//
//	// 这里需要free(p2)吗？
//	free(p3);
//}


//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//
//	// 动态申请10个int类型的空间
//int* ptr6 = new int[10] {1, 2, 3, 4, 5};
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


//int main()
//{
//	A* ptr1 = new A;             //operator new + 1次构造
//	A* ptr2 = new A[10];		 //operator new[ ] + 10次构造
//
//	delete ptr1;                 //1次析构 + operator delete
//	delete[] ptr2;               //?次析构 + operator delete[]
//
//	return 0;
//}



//int main()
//{
//	int* p1 = new int[10];
//	delete p1;
//	return 0;
//}

//class A
//{
//public:
//	A();
//	~A();
//
//private:
//
//};
//
//A::A()
//{
//}
//
//A::~A()
//{
//}
//
//int main()
//{
//	A* p2 = new A[10];
//	delete p2;
//	return 0;
//}



/*
operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
失败，尝试执行空间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常
*/
//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//	{
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK);  /* block other threads */
//	__TRY
//		        /* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	         /* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK);  /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define   free(p)               _free_dbg(p, _NORMAL_BLOCK)



class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};// 定位new/replacement new
int main()
{
	// p1现在指向的是与A对象相同大小的一段空间，还不能算对象，因为构造函数没有执行
	A* p1 = (A*)malloc(sizeof(A));
	new(p1)A;  			// Tips：如果A类的构造函数有参数时，此处需要传参
	p1->~A();
	free(p1);
	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
	return 0;
}