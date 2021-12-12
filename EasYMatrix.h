/*
* EasYMatrix —— By YYYCZ
* EasYMatrix 意为简单的矩阵，旨在用最轻量化的代码，最简单的方法，最简单的使用，实现矩阵相关的诸多功能
* EasYMatrix 提供了一种矩阵模板类 Matrix （只要提供矩阵内元素的类型即可） 和 一种矩阵引用类 RMatrix （可以实现对矩阵的部分操作）
* 
* 需要注意，该矩阵是在命名空间 EasYMatrix 下的
* 
* Matrix 中的 type 需要提供的函数（复数推荐使用C++内置的complex进行封装，否则可能有不可预知的错误）：
* 1.sqrt - 开方
* 2.conj - 取共轭
* 3.abs - 取绝对值（复数的话就是取模值）
* 4.norm - 求模长平方（非复数就是直接平方）
* 5.real - 取复数的实部
* 6.imag - 取复数的虚部
*/

/*
* 更新日志 | Start | By YYYCZ
* 1.实现了矩阵的基本功能
* 2.实现了矩阵的输入和输出
* 3.确立了Debug下的报错机制
* 
* 
* 
* 更新日志 | 2021 - 9 | By YYYCZ
* 1.加入矩阵的初等行列变换运算
* 2.定义了矩阵的输出格式类
* 
* 
* 
* 更新日志 | 2021 - 10 - 07 | By YYYCZ
* 1.加入了高斯消元和高斯若当消元算法
* 2.加入了施密特正交化算法
* 3.加入了满秩分解算法
* 4.加入了 1-范数， 无穷范数， Frobenius 范数的计算
* 5.加入了对角积，迹的计算
* 6.加入了矩阵逆，行列式的计算
* 7.加入了 LU 分解算法
* 
* 
* 
* 更新日志 | 2021 - 10 - 08 | By YYYCZ
* 1.引入了引用矩阵类 RMatrix （实际上是在 Matrix 上实现的）
* 2.将截取矩阵类的函数（如 Row、SubMatrix 等）的返回值改为 RMatrix
* 3.加入 Copy 函数，可以将 RMatrix 转为非引用 Matrix
* 4.加入 Assign 函数，RMatrix 调用此函数可以修改引用的值（普通赋值会修改引用）
* 5.RMatrix 可以通过初始化列表批量修改值
* 注意：请勿给 RMatrix 调用某些赋值类函数（如 SetOne、SetRandom 等），或引发未知错误
* 
* 
* 
* 更新日志 | 2021 - 10 - 09 | By YYYCZ
* 1.修复了引用类的赋值类函数问题（现在引用类可以调用赋值类函数了）
* 2.增加了对引用类编译检查
* 3.修复了引用类矩阵的 Resize 和 Splicing 问题
* 4.利用引用类优化了部分算法
* 5.实现矩阵间的比较以生成布尔矩阵（BoolMatrix）
* 6.实现了矩阵索引
* 7.加入了自定义计算、比较、计数方法
* 8.加入 Reshape 方法，原元素按顺序重新分配
* 9.加入 Take 方法，可以令矩阵中的非零元素用另一个矩阵的元素按顺序替换
* 10.加入 Mask 方法，可以让矩阵进行掩码
* 11.加入了 Householder 变换 和 Givens 变换
* 
* 
* 
* 更新日志 | 2021 - 10 - 10 | By YYYCZ
* 1.提高了对复数的支持程度
* 2.加入了 2-范数 的计算
* 3.加入了 幂法 和 瑞利商迭代
* 4.加入了 共轭 和 共轭转置 方法
* 5.优化部分函数
* 6.修复部分原先复数矩阵会产生的bug
* 7.加入了阈值函数 Threshold
* 8.改进了 Row、Column 等函数
* 9.更多的使用 C++ 库函数
* 10.编译检查增加
* 
* 
* 
* 更新日志 | 2021 - 10 - 11 | By YYYCZ
* 1.增加矩阵的 逐项相乘（Mutiply）、逐项相除（\）、逐项相余（Surplus）
* 2.加入了 FlipLeftAndRight、FlipUpAndDown、Rotate90 的方法（左右翻转、上下翻转、逆时针旋转任意个90度[默认一个]）
* 3.阈值函数 Threshold 第一个参数改为初始化列表
* 4.加入自动阈值函数 AutoThreshold
* 5.加入了 QR分解算法
* 6.加入的 AbsoluteTrace 绝对迹的计算
* 7.加入了 QRIteration 迭代方法计算特征值
* 8.加入 UpperHessenbergTransformation 方法
* 
* 
* 
* 更新日志 | 2021 - 10 - 12 | By YYYCZ
* 1.将 Householder变换 拆分成多个函数 - 生成向量、左乘、右乘
* 2.优化了部分算法
* 3.新增下标对索引获取部分矩阵 - [] 选取行列 - () 矩形区域
* 4.完善 QRIteration 算法
* 5.增加了三角矩阵的乘法算法
* 
* 
* 
* 更新日志 | 2021 - 10 - 13 | By YYYCZ
* 1.进一步细化 Householder 算法
* 2.加入 双对角化 和 三对角化 方法
* 3.加入 Jacobi 方法
* 4.加入 SVD 奇异值分解方法
* 
* 
* 
* 更新日志 | 2021 - 10 - 14 | By YYYCZ
* 1.实现扩充基方法
* 2.完善 SVD 奇异值分解算法
* 3.加入零元降维方法
* 4.加入 标准化 方法
* 5.加入 缩放 方法
* 6.优化了部分算法
* 7.加入求 伪逆矩阵 的方法
* 
* 
* 
* 更新日志 | 2021 - 10 - 17 | By YYYCZ
* 1.精简代码（将报错放到一个函数中实现）
* 2.将 Givens 旋转 和 Jacobi 旋转拆分
* 3.加入 舒尔分解 方法
* 4.弃用 QRIteration 方法，全部改用 舒尔分解
* 5.弃用 三角乘法 函数
* 
* 
* 
* 更新日志 | 2021 - 10 - 18 | By YYYCZ
* 1.加入了求指数对称化的比例系数函数
* 2.优化了 Givens 旋转矩阵生成算法
* 3.优化了 FrobeniusNorm 算法
* 4.优化了 Householder 旋转矩阵生成算法
* 5.优化了标准化函数，自动缩放函数改名为归一化函数
* 6.修复初等行列交换在引用矩阵下的bug
* 
* 
* 
* 更新日志 | 2021 - 10 - 22 | By YYYCZ
* 1.修复 Eigvalues 函数求出来的不是特征向量的BUG
* 
* 
* 
* 更新日志 | 2021 - 12 - 06 | By YYYCZ
* 1.修复 SVD 分解当列数大于行数时的bug
* 2.优化了 SetRandom 函数
* 3.修复了矩阵拷贝、Resize 和 Reshape 不能清空矩阵的bug
* 
* 
* 
* 更新日志 | 2021 - 12 - 08 | By YYYCZ
* 1.给 QR 分解添加了是否完整分解的选项
* 2.施密特正交化允许同时获取 R 矩阵
* 3.修复截取部分矩阵的bug
* 
* 
* 
* 更新日志 | 2021 - 12 - 09 | By YYYCZ
* 1.完善 Householder 变换相关操作
* 2.完善索引对 _Ip
* 
* 
* 
*/

#pragma once
#ifndef _EasYMatrix_
#define _EasYMatrix_

#include<type_traits>
#include<initializer_list>
#include<functional>
#include<complex>
#include<algorithm>
#include<utility>

#ifndef __DONT_USE_IOSTREAM__
#include<iostream>
#endif

#pragma push_macro("new")
#pragma push_macro("EMSelf")
#undef new
#undef EMSelf

#define EasYMatrix_Head(type) \
template<class _Tt> type Matrix<_Tt>::

#define EMSelf typename Matrix<_Tt>::

namespace EasYMatrix
{
	//释放标准库函数
	using std::conj;
	using std::abs;
	using std::norm;
	using std::real;
	using std::imag;

	//判断一个类型是否为 reference_wrapper
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v = false;
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v<std::reference_wrapper<_Ty>> = true;
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v<std::reference_wrapper<const _Ty>> = true;
	template <class _Ty>
	struct is_reference_wrapper : std::bool_constant<is_reference_wrapper_v<_Ty>> {};

	//移除 _Ty 的 reference_wrapper
	template<class _Ty>
	struct remove_reference_wrapper
	{
		using type = _Ty;
	};
	template<class _Ty>
	struct remove_reference_wrapper<std::reference_wrapper<_Ty>>
	{
		using type = std::decay_t<_Ty>;
	};
	
	//将参数包打包成数组，需要用<_Ty>指定类型
	template<class _Ty>
	inline void PackIntoArray(_Ty* _array_) {}

	template<class _Ty, class ..._Valty>
	inline void PackIntoArray(_Ty* _array_, const _Ty& _value_, _Valty&&... _package_)
	{
		*_array_++ = _value_;
		PackIntoArray<_Ty>(_array_, _package_...);
	}

	//获取最大值
	template<class _Ptr_, class _Meth_>
	_Ptr_ getMax(_Ptr_ _begin_, _Ptr_ _end_, _Meth_ _method_)
	{
		_Ptr_ max_ptr = _begin_;
		while (_begin_ != _end_)
			if (_method_(max_ptr) < _method_(_begin_++))
				max_ptr = _begin_;
		return max_ptr;
	}

	//是否是复数类 - C++自带
	template<class _Tt>
	struct IsComplex_
	{
		static constexpr bool value = false;
	};
	template<class _Tt>
	struct IsComplex_<std::complex<_Tt>>
	{
		static constexpr bool value = true;
	};

	//移除复数类
	template<class _Ty>
	struct remove_complex
	{
		using type = _Ty;
	};
	template<class _Ty>
	struct remove_complex<std::complex<_Ty>>
	{
		using type = std::decay_t<_Ty>;
	};

	//EasYMatrix - 矩阵类
	template<class _Tt>
	class Matrix
	{
	public:
		//非引用类型
		using _Ty = typename remove_reference_wrapper<_Tt>::type;
		//矩阵储存类型 - 模板所给类型
		using _Pt = _Tt;
		//引用类型
		using _Rt = std::reference_wrapper<_Ty>;
		//原始矩阵类型 - 与自身类型相同
		using _Self = Matrix<_Pt>;
		//非引用矩阵类型
		using _NSelf = Matrix<_Ty>;
		//引用矩阵类型
		using _RSelf = Matrix<_Rt>;
		//索引对
		struct _Ip
		{
			int first = 0;
			int second = -1;
			_Ip() = default;
			_Ip(int f, int s = -1) :first(f), second(s) {}
			_Ip(size_t f, int s = -1) :second(s) { first = f; }
			_Ip(int f, size_t s) :first(f)
			{
				second = s;
			}
			_Ip(size_t f, size_t s)
			{
				first = f;
				second = s;
			}
		};

		//复数类型
		using _Ct = std::complex<typename remove_complex<_Ty>::type>;
		//复数矩阵类
		using _CSelf = Matrix<_Ct>;
		//复数引用矩阵类
		using _CRSelf = Matrix<std::reference_wrapper<_Ct>>;

		//保证不同类型间的 Matrix 的 protect 和 private 中的方法和变量可以相互调用
		template<class _TT> friend class Matrix;

	public:
		static _Ty _Zero_;//零元
		static _Ty _Unit_;//单位元
		static _Ty _Default_;//默认元

#ifdef _IOSTREAM_
		//矩阵输入
		template<class _TT> friend std::istream& operator>> (std::istream& in, Matrix<_TT>& _matrix_);
		template<class _TT> friend std::enable_if_t<is_reference_wrapper_v<_TT>, std::istream&> 
			operator>>(std::istream& in, const Matrix<_TT>& _matrix_);
		//矩阵输出
		template<class _TT> friend std::ostream& operator<< (std::ostream& out, const Matrix<_TT>& _matrix_);
#endif

		//把 _Pt 引用转到 _Ty 引用
		static constexpr _Ty& PtCast(_Pt& ptv);

		//复数强转
		template<class _RV>
		std::enable_if_t<!IsComplex_<_Ty>::value, _RV> ComCast(const std::complex<_RV>& _com_) { return real(_com_); };
		template<class _RV>
		static constexpr _RV& ComCast(const _RV& _com_) { return const_cast<_RV&>(_com_); }

	protected:	/* 矩阵里一些基本的数据和方法 */
		_Pt* form = nullptr;	//矩阵的内存地址
		size_t capacity = 0;	//矩阵占用内存空间的大小
		size_t row = 0;			//矩阵行数
		size_t column = 0;		//矩阵列数

		//为 form 分配内存
		void _Allocate_(size_t _size_);

		//释放 form 的内存
		void _Deallocate_();

		//用一块新的内存空间保存矩阵，重叠部分（即新旧矩阵都包含的部分）会拷贝过去，非重叠部分用 _value_ 填充
		void _NewForm_(size_t _row_, size_t _column_, const _Ty& _value_, bool _to_set_value_ = true);

		//把矩阵占用的内存释放掉
		void _FreeForm_() noexcept;

		//对矩阵进行深拷贝
		template<class _RV>
		void _CopyForm_(_RV* _array_, size_t _row_, size_t _column_);

		//debug模式下报错
		void _DebugError_(bool error_condition, const char* function_name, const char* error_msg) const;

	public:		/* 构造、析构与内存相关 */

		//析构，把矩阵占的内存释放掉
		~Matrix() noexcept;

		//初始化一个空矩阵
		Matrix() = default;

		//提供单个或多个元素直接构造矩阵
		Matrix(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_) noexcept;
		
		//提供行数、列数构造一个矩阵
		Matrix(size_t _row_, size_t _column_) noexcept;

		//提供行数、列数和初始值构造一个矩阵
		Matrix(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//拷贝构造（可以是不同类型的矩阵）
		Matrix(const _Self& _matrix_) noexcept;
		_Self& operator=(const _Self& _matrix_) noexcept;
		template<class _RV>
		Matrix(const Matrix<_RV>& _matrix_) noexcept;
		template<class _RV>
		_Self& operator=(const Matrix<_RV>& _matrix_) noexcept;
		template<class _RV>
		_Self& Assgin(const Matrix<_RV>& _matrix_) noexcept;

		//值拷贝
		_Self& operator=(const _Ty& _value_) noexcept;
		_Self& Assgin(const _Ty& _value_) noexcept;

		//通过初始化列表拷贝
		_Self& operator=(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_);

		//用数组来初始化矩阵
		template<class _RV>
		Matrix(const _RV* _array_, size_t _row_, size_t _column_);

		//用函数来初始化矩阵
		Matrix(std::function<_Pt(size_t, size_t)> _method_, size_t _row_, size_t _column_);

		//实现矩阵的类型转换（显式调用）
		template<class _RV>
		explicit operator Matrix<_RV>();

		//矩阵拷贝
		_NSelf Copy();

		//交换两个矩阵的内存（即会将矩阵中的元素交换）
		template<class _RV>
		_Self& Swap(Matrix<_RV>& _matrix_);
		
		//重新设置矩阵大小
		_Self& Resize(size_t _row_, size_t _column_) noexcept;

		//重新设置矩阵大小，新增部分设值为 _value_
		_Self& Resize(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//重新设置矩阵大小，原本元素按顺序填充
		_Self& Reshape(size_t _row_, size_t _column_) noexcept;

		//重新设置矩阵大小，原本元素按顺序填充，新增部分设值为 _value_
		_Self& Reshape(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//设置矩阵所有元素的值为同一个值 _value_
		_Self& SetValue(const _Ty& _value_) noexcept;

		//设置矩阵为单位矩阵
		_Self& SetIdentity(size_t _dim_) noexcept;

		//将矩阵中的每一个元素随机赋值
		//需要提供随机数生成函数
		template<class _Pred>
		_Self& SetRandom(_Pred pf) noexcept;

		//清空矩阵（不清除占用的内存）
		_Self& Clear() noexcept;

		//获取矩阵的元素占用的内存大小
		size_t Memory() const noexcept;

	public:		/* 矩阵位置、大小相关 */

		//获取矩阵行数
		size_t Rows() const noexcept;

		//获取矩阵列数
		size_t Columns() const noexcept;

		//获取矩阵元素个数
		size_t Size() const noexcept;

		//矩阵是否为空
		bool Empty() const noexcept;

		//获取矩阵的某个位置上的元素
		_Ty& operator()(size_t _row_, size_t _column_);
		const _Ty& operator()(size_t _row_, size_t _column_) const;
		_Ty& operator[](size_t _idx_);
		const _Ty& operator[](size_t _idx_) const;

		//获取部分行列的矩阵
		_RSelf operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_);
		_NSelf operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_) const;

		//用一个矩阵截取矩阵
		//非 const 返回引用类列向量
		//const 返回拷贝列向量
	protected:
		template<class _RV, class _Mt>
		Matrix<_Mt> _Index_(const Matrix<_RV>&_idx_matrix_) const;
	public:
		template<class _RV>
		_RSelf operator()(const Matrix<_RV>&_idx_matrix_);
		template<class _RV>
		_NSelf operator()(const Matrix<_RV>&_idx_matrix_, bool _PLACEHOLDER_ = true) const;

		//将矩阵中的非零元素用替换矩阵的元素按顺序替换
		template<class _RV>
		auto Take(const Matrix<_RV>&_rpl_matrix_) const;

		//用另一个矩阵对该矩阵进行掩码
		template<class _RV>
		_Self& Mask(const Matrix<_RV>& _kernel_matrix_);

		//获取矩阵的一行或多行
		//支持用索引矩阵索引
	protected:
		template<class _RV>
		Matrix<_RV> Row(const size_t * _index_list_, size_t _size_) const;
	public:
		_RSelf Row(std::initializer_list<size_t> _multiple_index_);
		_NSelf Row(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf Row(const Matrix<size_t>& _index_matrix_);
		_NSelf Row(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//获取矩阵的一列或多列
		//支持用索引矩阵索引
	protected:
		template<class _RV>
		Matrix<_RV> Column(const size_t * _index_list_, size_t _size_) const;
	public:
		_RSelf Column(std::initializer_list<size_t> _multiple_index_);
		_NSelf Column(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf Column(const Matrix<size_t>& _index_matrix_);
		_NSelf Column(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//划去矩阵一行或多行
	protected:
		template<class _RV>
		Matrix<_RV> RowCrossOut(const size_t* _index_list_, size_t _size_) const;
	public:
		_RSelf RowCrossOut(std::initializer_list<size_t> _multiple_index_);
		_NSelf RowCrossOut(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf RowCrossOut(const Matrix<size_t>& _index_matrix_);
		_NSelf RowCrossOut(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//划去矩阵的一列或多列
	protected:
		template<class _RV>
		Matrix<_RV> ColumnCrossOut(const size_t* _index_list_, size_t _size_) const;
	public:
		_RSelf ColumnCrossOut(std::initializer_list<size_t> _multiple_index_);
		_NSelf ColumnCrossOut(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf ColumnCrossOut(const Matrix<size_t>& _index_matrix_);
		_NSelf ColumnCrossOut(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//按矩形截取部分矩阵
	protected:
		template<class _RV>
		Matrix<_RV> SubMatrix(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_) const;
	public:
		_RSelf SubMatrix(size_t _row_end_, size_t _column_end_);
		_RSelf SubMatrix(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_);
		_NSelf SubMatrix(size_t _row_end_, size_t _column_end_, bool _PLACEHOLDER_ = true) const;
		_NSelf SubMatrix(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_, bool _PLACEHOLDER_ = true) const;
		_RSelf operator()(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_);
		_NSelf operator()(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_, bool _PLACEHOLDER_ = true) const;
		_RSelf operator()(_Ip _row_, _Ip _column_ = { 0,-1 });
		_NSelf operator()(_Ip _row_, _Ip _column_ = { 0,-1 }, bool _PLACEHOLDER_ = true) const;

		//拼接上一个矩阵（有左右、上下两种模式）
		//默认左右拼接
		//注意：拼接矩阵必须行列匹配
	protected:
		template<class _RV>
		Matrix<_RV> Splicing(const _Self& _matrix_, bool left_right = true) const;
	public:
		_RSelf Splicing(_Self & _matrix_, bool left_right = true);
		_NSelf Splicing(const _Self& _matrix_, bool left_right = true, bool _PLACEHOLDER_ = true) const;

	public:		/* 矩阵的旋转、对称 */

		//矩阵转置
		_NSelf Transpose() const;

		//共轭转置
		_NSelf ConjugateTranspose() const;

		//上下翻转
		_NSelf FlipUpAndDown() const;

		//左右翻转
		_NSelf FlipLeftAndRight() const;

		//逆时针旋转 n 个 90°
		_NSelf Rotate90(int _n_ = 1) const;

	public:		/* 矩阵的比较  */

		//比较函数，需要提供比较方法
		template<class _RV, class _BL>
		Matrix<bool> Compare(const Matrix<_RV>& _matrix_, std::function<_BL(const _Tt&, const _RV&)> _method_) const;
		template<class _RV, class _BL>
		Matrix<bool> Compare(const _RV& _value_, std::function<_BL(const _Tt&, const _RV&)> _method_) const;

		//等于
		template<class _RV>
		Matrix<bool> operator==(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator==(const _RV& _value_) const;

		//不等于
		template<class _RV>
		Matrix<bool> operator!=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator!=(const _RV& _value_) const;

		//大于
		template<class _RV>
		Matrix<bool> operator>(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator>(const _RV& _value_) const;

		//小于
		template<class _RV>
		Matrix<bool> operator<(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator<(const _RV& _value_) const;

		//大于等于
		template<class _RV>
		Matrix<bool> operator>=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator>=(const _RV& _value_) const;

		//小于等于
		template<class _RV>
		Matrix<bool> operator<=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator<=(const _RV& _value_) const;

	public:		/* 矩阵的逐运算 */

		//令矩阵的每一项与另外一个矩阵的对应项进行运算
		template<class _RV>
		_Self& Calculate(const Matrix<_RV>& _matrix_, std::function<void(_Pt&, const _RV&)> _method_);

		//令矩阵的每一项与一个数进行计算 - 数量运算
		template<class _RV>
		_Self& Calculate(const _RV& _value_, std::function<void(_Pt&, const _RV&)> _method_);

		//令矩阵的每一项进行一种运算 - 自运算
		_Self& Calculate(std::function<void(_Pt&)> _method_);

		//计数函数 - 遍历矩阵的每一项，计算出一个结果
		template<class _RV>
		_RV Count(_RV _original_value_, std::function<void(_RV&, const _Ty&)> _method_) const;

		//计数函数 - 获取矩阵中某一项的个数
		size_t Count(const _Ty& _value_) const;

	public:		/* 矩阵的位运算 */

		//与运算
		template<class _RV>
		_Self& operator&=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator&(const Matrix<_RV>& _matrix_);

		//或运算
		template<class _RV>
		_Self& operator|=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator|(const Matrix<_RV>& _matrix_);

		//异或运算
		template<class _RV>
		_Self& operator^=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator^(const Matrix<_RV>& _matrix_);

		//数量与运算
		template<class _RV>
		_Self& operator&=(const _RV& _value_);
		template<class _RV>
		auto operator&(const _RV& _value_) const;

		//数量或运算
		template<class _RV>
		_Self& operator|=(const _RV& _value_);
		template<class _RV>
		auto operator|(const _RV& _value_) const;

		//数量异或运算
		template<class _RV>
		_Self& operator^=(const _RV& _value_);
		template<class _RV>
		auto operator^(const _RV& _value_) const;

	public:		/* 矩阵的基本运算 */

		//矩阵取非
		_NSelf operator!() const;

		//矩阵取负
		_NSelf operator-() const;

		//矩阵取共轭
		_NSelf operator~() const;

		//矩阵加法
		template<class _RV>
		_Self& operator+=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator+(const Matrix<_RV>& _matrix_) const;

		//矩阵减法
		template<class _RV>
		_Self& operator-=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator-(const Matrix<_RV>& _matrix_) const;

		//矩阵乘法
		template<class _RV>
		_Self& operator*=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator*(const Matrix<_RV>& _matrix_) const;

		//矩阵内积和
		template<class _RV>
		auto operator%(const Matrix<_RV>& _matrix_) const;

		//矩阵数量加法
		template<class _RV>
		_Self& operator+=(const _RV& _value_);
		template<class _RV>
		auto operator+(const _RV& _value_) const;

		//矩阵数量减法
		template<class _RV>
		_Self& operator-=(const _RV& _value_);
		template<class _RV>
		auto operator-(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator-(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//矩阵数量乘法
		template<class _RV>
		_Self& operator*=(const _RV& _value_);
		template<class _RV>
		auto operator*(const _RV& _value_) const;

		//矩阵数量除法
		template<class _RV>
		_Self& operator/=(const _RV& _value_);
		template<class _RV>
		auto operator/(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator/(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//矩阵数量取余
		template<class _RV>
		_Self& operator%=(const _RV& _value_);
		template<class _RV>
		auto operator%(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator%(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//矩阵逐项相乘
		template<class _RV>
		_Self& Mutiply(const Matrix<_RV>& _matrix_);

		//矩阵逐项相除
		template<class _RV>
		_Self& operator/=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator/(const Matrix<_RV>& _matrix_) const;

		//矩阵逐项相余
		template<class _RV>
		_Self& operator%=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		_Self& Surplus(const Matrix<_RV>& _matrix_);

	public:		/* 初等行、列变换 */

		//交换两行
		_Self& RowExchange(size_t _row1_, size_t _row2_);

		//交换两列
		_Self& ColumnExchange(size_t _column1_, size_t _column2_);

		//让某行乘上一个数
		_Self& RowMultiply(size_t _row_, const _Ty& _value_);

		//让某列乘上一个数
		_Self& ColumnMultiply(size_t _column_, const _Ty& _value_);

		//让某行加上某行的任意倍
		//注：是 row1 加上 value 倍的 row2
		_Self& RowAdd(size_t _row1_, size_t _row2_, const _Ty& _value_ = _Unit_);

		//让某列加上某行的任意倍
		//注：是 column1 加上 value 倍的 column2
		_Self& ColumnAdd(size_t _column1_, size_t _column2_, const _Ty& _value_ = _Unit_);

	public:		/* 行列式、逆矩阵 */

		//计算矩阵的迹
		_Ty Trace() const;

		//计算矩阵的绝对值的迹
		auto AbsoluteTrace() const;

		//计算矩阵的对角积
		_Ty Diagonal() const;

		//计算矩阵的行列式的值
		_Ty Determinant() const;

		//求矩阵的逆矩阵
		_NSelf Inverse() const;

	public:		/* 矩阵范数 */

		//阈值函数
		//到某点的模值平方小于阈值的元素置为该点的值
		_Self& Threshold(std::initializer_list<_Ty> points = { _NSelf::_Zero_ }, const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6);
		
		//自动阈值函数
		//去除过小的 实部 或 虚部
		_Self& AutoThreshold(const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6);

		//求矩阵的 Frobenius 范数
		auto FrobeniusNorm() const;

		//求矩阵的 无穷-范数
		auto InfiniteNorm() const;

		//求矩阵的 1-范数
		auto OneNorm() const;

		//求矩阵的 2-范数
		auto TwoNorm(const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

	public:		/* 矩阵的特征值 */

		//求矩阵的模最大特征值的模
		//幂法 - 通常较快
		_Ty PowerMethod(const decltype(norm(std::declval<_Ty>()))&  max_error = 1e-6) const;

		//求矩阵的模最大特征值的模
		//瑞利商算法 - 较慢
		_Ty RayleighQuotientIteration(const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//获取雅可比旋转矩阵
		_NSelf JacobiMatrix(size_t idx1, size_t idx2);

		//雅可比旋转
		//可填入获取特征向量的矩阵
		//限定：对称矩阵
		_Self& JacobiRotatation(size_t idx1, size_t idx2, _NSelf* eig_vecs = nullptr);

		//双边雅可比方法
		//求出矩阵的全部特征值
		//可填入获取特征向量的矩阵
		//限定：对称矩阵（注意：非对称矩阵会陷入死循环！）
		//注意：返回结果为对角元素全为特征值的方阵 - 列向量为特征向量
		_NSelf BilateralJacobiMethod(_NSelf* eig_vecs = nullptr, const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//求特征值及特征向量
		_CSelf Eigvalues(_CSelf* eig_vecs = nullptr, const decltype(norm(std::declval<_Ty>())) & max_error = 1e-6);

	public:		/* LU分解 */

		//让矩阵进行高斯消元
		//采用部分主元法
		_Self& GaussianElimination();

		//让矩阵进行高斯-若当消元
		_Self& GaussJordanElimination();

		//让矩阵进行 LU 分解
		//注意：返回的是 L 的逆矩阵 和 U 矩阵
		void LUDecomposition(_NSelf& _Linv_, _NSelf& _U_) const;

	public:		/* QR分解 */

		//Gram - Schmidt 正交化 （对列向量）
		//实际中可能前 k 列已经是正交基，这时可指定前几列是正交基，默认为0
		_Self& GramSchmidtOrthogonalization(_NSelf* _R_ = nullptr, size_t _column_start_ = 0);

		//获取 Householder 变换向量
		//需要指明以哪个位置作为基准位置（生成能将该元素下面的元素全部消去的向量）
		_NSelf HouseholderVector(size_t _row_, size_t _column_, bool erase_column = true, bool erase_back = true);

		//用 Householder 向量 v 生成矩阵 H 左乘于矩阵
		//需要提供 v 的有效部分从哪个位置开始 以及 矩阵列的有效部分从哪开始
		_Self& HouseholderLeft(const _NSelf& _v_, _Ip _v_range_ = { 0,-1 }, _Ip _m_range_ = { 0,-1 }, bool erase_column = true);

		//用 Householder 向量 v 生成矩阵 H 右乘于矩阵
		//需要提供 v 的有效部分从哪个位置开始 以及 矩阵行的有效部分从哪开始
		_Self& HouseholderRight(const _NSelf& _v_, _Ip _v_range_ = { 0,-1 }, _Ip _m_range_ = { 0,-1 }, bool erase_column = true);

		//Householder变换
		//可以设定起始行
		_Self& HouseholderTransformation(size_t _start_row_ = 0);

		//获取Givens变换矩阵
		_NSelf GivensMatrix(size_t _column_, size_t _row_use_, size_t _row_erase_);

		//获取双边Givens变换矩阵
		_NSelf BilateralGivensMatrix(size_t row1, size_t row2, size_t column1, size_t column2);

		//左乘Givens变换矩阵
		_Self& GivensLeft(const _NSelf& _givens_matrix_, size_t _row1_, size_t _row2_);

		//右乘Givens变换矩阵
		_Self& GivensRight(const _NSelf& _givens_matrix_, size_t _column1_, size_t _column2_);

		//单次Givens变换
		//需要指明对第几列，用哪一行消去哪一行
		_Self& Givens(size_t _column_, size_t _row_use_, size_t _row_erase_);
		
		//Givens变换
		//可以设定起始行
		_Self& GivensTransformation(size_t _start_row_ = 0);

		//让矩阵进行 QR 分解
		void QRDecomposition(_NSelf& _Q_, _NSelf& _R_, bool full = true) const;

	public:		/* 满秩分解 */

		//对矩阵作满秩分解
		void FullRankDecomposition(_NSelf& _F_, _NSelf& _G_) const;

		//扩充基
		//需要指定目前的秩是多少
		//注：对列向量进行扩充
		_Self& ExtendBase(size_t _rank_);

	public:		/* 舒尔分解 */

		//对矩阵作舒尔分解
		void SchurDecomposition(_NSelf& _T_, _NSelf* _U_ = nullptr,const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

	public:		/* 奇异值分解 */

		//对矩阵作奇异值分解
		//分解得到 A = US(V^T)
		//其中 A 是 m*n 矩阵， U 是 m*m 正交矩阵， S 是 m*n 对角阵， V 是 n*n 正交矩阵
		//其中 S 必须获取， V 和 U 可以选择获取
		//U、V 同时存在，优先计算 V，如果想要优先计算 U，请先对矩阵进行转置
		void SVDDecomposition(_NSelf& _S_, _NSelf* _V_ = nullptr, _NSelf* _U_ = nullptr,
			const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//求伪逆矩阵
		_NSelf PseudoInverse() const;

	public:		/* 矩阵的正交化变形 */

		//上 Hessenberg 化
		_Self& UpperHessenbergTransformation();

		//双对角化
		_Self& Bidiagonalization();

		//三对角化
		_Self& Tridiagonalization();

	public:		/* 矩阵预处理 */

		//自动清除全为 0 的行和列
		//可以获取清除掉的 行和列
		_Self& ZeroReduction(const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6,
			Matrix<size_t>* rows_clear = nullptr, Matrix<size_t>* column_clear = nullptr);

		//矩阵标准化
		//可获取均值和标准差
		_Self& Standardization(_Ty* _mean_ = nullptr, _Ty* _standard_deviation_ = nullptr);

		//矩阵归一化
		//可获取缩放系数
		_Self& Normalization(_Ty* _Coe = nullptr);

		//获取缩放系数（缩放到 rmin * rmax = 1）
		auto ScalingCoefficient() const;
	};

	//引用类型矩阵
	template<class _Ty>
	using RMatrix = Matrix<typename std::reference_wrapper<_Ty>>;

	//布尔矩阵
	typedef Matrix<bool> BoolMatrix;
	typedef RMatrix<bool> BoolRMatrix;

	//索引矩阵
	typedef Matrix<size_t> IndexMatrix;
	typedef RMatrix<size_t> IndexRMatrix;

	//复数矩阵
	template<class _Ty>
	using ComplexMatrix = Matrix<std::complex<_Ty>>;
	template<class _Ty>
	using ComplexRMatrix = RMatrix<std::complex<_Ty>>;

	EasYMatrix_Head(EMSelf _Ty)
		_Default_ = _Ty();

	EasYMatrix_Head(EMSelf _Ty)
		_Zero_ = _Ty();

	//宏定义 _EasYMatrix_NO_UNIT_ 可以取消默认单位元的设置（考虑到 _Ty(1) 可能无法实现）
#ifndef _EasYMatrix_NO_UNIT_

	EasYMatrix_Head(EMSelf _Ty)
		_Unit_ = _Ty(1);

#endif 
	
#ifdef _IOSTREAM_
	//矩阵的输入
	template<class _Ty>
	std::istream& operator>>(std::istream& in, Matrix<_Ty>& _matrix_)
	{
		auto write_ptr = _matrix_.form;
		size_t _size_ = _matrix_.row * _matrix_.column;

		for (size_t i = 0; i < _size_; i++)
			in >> *write_ptr++;

		return in;
	}

	template<class _Ty>
	std::enable_if_t<is_reference_wrapper_v<_Ty>, std::istream&>
		operator>>(std::istream& in, const Matrix<_Ty>& _matrix_)
	{
		auto write_ptr = _matrix_.form;
		size_t _size_ = _matrix_.row * _matrix_.column;

		for (size_t i = 0; i < _size_; i++)
			in >> write_ptr++->get();

		return in;
	}

	static struct
	{
		const char* PreText = "{[";			//输出矩阵前输出的文本
		const char* PostText = "]}";		//输出矩阵后输出的文本

		const char* RowPreText = " [";		//输出矩阵一行前输出的文本
		const char* RowPostText = "],\n";	//输出矩阵一行后输出的文本

		const char* ColumnText = ", ";		//输出矩阵每列间输出的文本

		size_t OutLength = 10;				//输出长度 - 仅在导入 iomanip 后有效
	}

	//控制矩阵输出格式的全局变量
	EasYMatrix_IOFormat;

	//矩阵的输出
	template<class _Ty>
	std::ostream& operator<<(std::ostream& out, const Matrix<_Ty>& _matrix_)
	{
		auto read_ptr = _matrix_.form;

		out << EasYMatrix_IOFormat.PreText;
		for (size_t i = 0; i < _matrix_.row; i++)
		{
			if(i) out << EasYMatrix_IOFormat.RowPreText;
			for (size_t j = 0; j < _matrix_.column; j++)
			{
				if(j) out << EasYMatrix_IOFormat.ColumnText;
#ifdef _IOMANIP_
				out << std::setw(EasYMatrix_IOFormat.OutLength) << Matrix<_Ty>::PtCast(*read_ptr++);
#else
				out << *read_ptr++;
#endif
			}
			if(i != _matrix_.row - 1) out << EasYMatrix_IOFormat.RowPostText;
		}
		out << EasYMatrix_IOFormat.PostText;

		return out;
	}

#endif

	//快速生成 Matrix<double> 的单位矩阵
	Matrix<double> operator""I(unsigned long long _Dim)
	{
		Matrix<double> result;
		result.SetIdentity(_Dim);
		return result;
	}

	//把 _Pt 引用转到 _Ty 引用
	EasYMatrix_Head(constexpr EMSelf _Ty&)
		PtCast(_Pt& ptv)
	{
		if constexpr (is_reference_wrapper_v<_Pt>)
			return ptv.get();
		return ptv;
	}

	//为 form 分配内存
	EasYMatrix_Head(void) 
		_Allocate_(size_t _size_)
	{
		std::allocator<_Pt> alloc;
		form = alloc.allocate(_size_);
		capacity = _size_;
	}

	//释放 form 的内存
	EasYMatrix_Head(void) 
		_Deallocate_()
	{
		std::allocator<_Pt> alloc;
		auto des_ptr = form + capacity;
		while(des_ptr != form)
			alloc.destroy(--des_ptr);
		alloc.deallocate(form, capacity);
		form = nullptr;
		capacity = 0;
	}

	/*
	* 为矩阵的 form 分配一块新的内存空间
	* 这里使用了内存分配器进行分配
	* 
	* 这里实现的方法是创建一块新的内存
	* 在 _to_set_value_ 为真的情况下，其会将矩阵中重叠的部分复制过去，并用 _value_ 给不重叠部分赋值
	*/
	EasYMatrix_Head(void) 
		_NewForm_(size_t _row_, size_t _column_, const _Ty& _value_, bool _to_set_value_)
	{
		//引用类矩阵谢绝赋初值
#ifdef _DEBUG
		if (_to_set_value_ && is_reference_wrapper_v<_Tt>)
		{
#ifdef _IOSTREAM_
			std::cerr << "EasYMatrix - NewForm - RMatrix can not be assgined to default value!" << std::endl;
#endif
			throw _to_set_value_;
		}
#endif

		//完全相同，没必要重新分配
		if (row == _row_ && column == _column_)
			return;

		//获取所需内存空间大小
		size_t _CapacityNeed = _row_ * _column_;

		if (form == nullptr)
		{
			//没有矩阵，直接创建新矩阵
			if (_row_ > 0 && _column_ > 0)
			{
				_Allocate_(_CapacityNeed);
				row = _row_;
				column = _column_;
				
				//根据 _to_set_value_ 的设置选择是否进行赋值
				//必须不是引用类矩阵
				if constexpr (!is_reference_wrapper_v<_Tt>)
				{
					if (_to_set_value_)
					{
						auto write_ptr = form;
						size_t _size_ = row * column;
						for (size_t i = 0; i < _size_; i++)
						{
							*write_ptr++ = _value_;
						}
					}
				}
			}
		}
		else
		{
			//行数或列数其一为零直接设置成空矩阵
			if (_row_ == 0 || _column_ == 0)
			{
				row = 0;
				column = 0;
			}
			else
			{
				_Pt* temp_form = form;
				size_t temp_form_size = capacity;
				bool to_free = false;
				//只有当当前内存量不足时才重新分配
				if (_CapacityNeed > capacity)
					_Allocate_(_CapacityNeed),
					to_free = true;

				//根据 _to_set_value_ 的设置选择是否进行赋值
				//必须不是引用类矩阵
				if constexpr (!is_reference_wrapper_v<_Tt>)
				{
					if (_to_set_value_)
					{
						auto write_ptr = form;		//写指针
						auto read_ptr = temp_form;	//读指针

						//以下四项 size_t 主要方便后面循环的使用
						size_t min_row = row < _row_ ? row : _row_,
							min_column = column < _column_ ? column : _column_;
						size_t _ori_row_add_ = column - min_column,
							_new_row_add_ = _column_ - min_column;

						//拷贝重叠部分
						for (size_t i = 0; i < min_row; i++,
							read_ptr += _ori_row_add_,
							write_ptr += _new_row_add_)
							for (size_t j = 0; j < min_column; j++)
								*write_ptr++ = *read_ptr++;

						//为空置部分赋值（右边）
						write_ptr = form + min_column;
						for (size_t i = 0; i < min_row; i++, write_ptr += min_column)
							for (size_t j = min_column; j < _column_; j++)
								*write_ptr++ = _value_;

						//为空置部分赋值（下边和右下边）
						write_ptr -= min_column;
						for (size_t i = min_row; i < _row_; i++)
							for (size_t j = 0; j < _column_; j++)
								*write_ptr++ = _value_;
					}
				}
				else
				{
					//引用类型必然会拷贝重叠部分
					auto write_ptr = form;		//写指针
					auto read_ptr = temp_form;	//读指针

					//以下四项 size_t 主要方便后面循环的使用
					size_t min_row = row < _row_ ? row : _row_,
						min_column = column < _column_ ? column : _column_;
					size_t _ori_row_add_ = column - min_column,
						_new_row_add_ = _column_ - min_column;

					//拷贝重叠部分
					for (size_t i = 0; i < min_row; i++,
						read_ptr += _ori_row_add_,
						write_ptr += _new_row_add_)
						for (size_t j = 0; j < min_column; j++)
							*write_ptr++ = *read_ptr++;
				}

				//设置成新的行数列数并释放原来矩阵占用的内存
				row = _row_;
				column = _column_;
				if (to_free)
				{
					std::allocator<_Pt> alloc;
					auto des_ptr = temp_form + temp_form_size;
					while (des_ptr != temp_form)
						alloc.destroy(--des_ptr);
					alloc.deallocate(temp_form, temp_form_size);
				}
			}
		}
	}

	//释放掉 form 占用的内存，并将 form 设为空指针
	//相当于把矩阵变为空矩阵
	EasYMatrix_Head(void) 
		_FreeForm_() noexcept
	{
		if (form != nullptr)
		{
			_Deallocate_();
			row = 0;
			column = 0;
		}
	}

	//通过指针、行数和列数来复制矩阵
	//考虑到不同类型的转换，这里用了函数模板
	EasYMatrix_Head(template<class _RV> void)
		 _CopyForm_(_RV* _array_, size_t _row_, size_t _column_)
	{
		size_t _CapacityNeed = _row_ * _column_;
		if (_array_ != nullptr && _row_ > 0 && _column_ > 0)
		{
			//设置为新的行数和列数，分配新的内存空间
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
				_Allocate_(_CapacityNeed);

			//其实相当于把 _array_ 看成其他矩阵的 form 来进行深拷贝
			//不过这里因为类型没有限制因此更有灵活性
			auto write_ptr = this->form;
			for (size_t i = 0; i < _CapacityNeed; i++)
				*write_ptr++ = ComCast(*_array_++);
		}
		else
		{
			this->row = 0;
			this->column = 0;
		}
	}

	//debug模式下报错
	EasYMatrix_Head(inline void)
		_DebugError_(bool error_condition, const char* function_name, const char* error_msg) const
	{
#ifdef _DEBUG
		if (error_condition)
#ifdef _IOSTREAM_
			std::cerr << "EasYMatrix - " << function_name << '\n' << error_msg << std::endl,
#endif 
			throw error_condition;
#endif
	}

	EasYMatrix_Head(inline)
		~Matrix() noexcept
	{
		_FreeForm_();
	}

	EasYMatrix_Head(inline)
		Matrix(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_) noexcept
	{
		//引用类矩阵不能调用此函数
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - Matrix - RMatrix can not be assgined to value!");

		_NewForm_(_mutiple_value_.size(), getMax(_mutiple_value_.begin(), _mutiple_value_.end(),
			[](const std::initializer_list<_Ty>* _ini_)->size_t {return _ini_->size(); })->size(), _Default_, false);
		if (form == nullptr) return;
		auto write_ptr = this->form;
		for (auto& i : _mutiple_value_)
			for (auto j : i)
				PtCast(*write_ptr++) = j;

		_DebugError_(form + Size() != write_ptr, "Matrix", "You have given a wrong initializer list!");
	}

	EasYMatrix_Head(inline)
		Matrix(size_t _row_, size_t _column_) noexcept
	{
		_NewForm_(_row_, _column_, _Default_, false);
	}

	EasYMatrix_Head(inline)
		Matrix(size_t _row_, size_t _column_, const _Ty& _value_) noexcept
	{
		//引用类矩阵不能调用此函数
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - Matrix - RMatrix can not be assgined to value!");

		_NewForm_(_row_, _column_, _value_);
	}

	EasYMatrix_Head(inline)
		Matrix(const _Self& _matrix_) noexcept
	{
		_CopyForm_<_Pt>(const_cast<_Pt*>(_matrix_.form), _matrix_.row, _matrix_.column);
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		operator=(const _Self& _matrix_) noexcept
	{
		_CopyForm_<_Pt>(const_cast<_Pt*>(_matrix_.form), _matrix_.row, _matrix_.column);
		return *this;
	}

	EasYMatrix_Head(template<class _RV> inline)
		Matrix(const Matrix<_RV>& _matrix_) noexcept
	{
		_CopyForm_<_RV>(const_cast<_RV*>(_matrix_.form), _matrix_.row, _matrix_.column);
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		operator=(const Matrix<_RV>& _matrix_) noexcept
	{
		_CopyForm_<_RV>(const_cast<_RV*>(_matrix_.form), _matrix_.row, _matrix_.column);
		return *this;
	}

	EasYMatrix_Head(EMSelf _Self&)
		operator=(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_)
	{
		_NewForm_(_mutiple_value_.size(), getMax(_mutiple_value_.begin(), _mutiple_value_.end(),
			[](const std::initializer_list<_Ty>* _ini_)->size_t {return _ini_->size(); })->size(), _Default_, false);
		if (form == nullptr) return *this;
		auto write_ptr = this->form;
		for (auto& i : _mutiple_value_)
			for (auto j : i)
				PtCast(*write_ptr++) = j;

		_DebugError_(form + Size() != write_ptr, "Matrix", "You have given a wrong initializer list!");

		return *this;
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		Assgin(const Matrix<_RV>& _matrix_) noexcept
	{
		size_t _row_ = _matrix_.row;
		size_t _column_ = _matrix_.column;
		auto _array_ = _matrix_.form;

		size_t _CapacityNeed = _row_ * _column_;
		if (_array_ != nullptr && _row_ > 0 && _column_ > 0)
		{
			//设置为新的行数和列数，分配新的内存空间
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
				_Allocate_(_CapacityNeed);

			//其实相当于把 _array_ 看成其他矩阵的 form 来进行深拷贝
			//不过这里因为类型没有限制因此更有灵活性
			auto write_ptr = this->form;
			for (size_t i = 0; i < _CapacityNeed; i++)
				PtCast(*write_ptr++) = ComCast(*_array_++);
		}
		else
		{
			this->row = 0;
			this->column = 0;
		}

		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&) 
		operator=(const _Ty& _value_) noexcept
	{
		return SetValue(_value_);
	}

	EasYMatrix_Head(inline EMSelf _Self&) 
		Assgin(const _Ty& _value_) noexcept
	{
		return SetValue(_value_);
	}

	EasYMatrix_Head(template<class _RV> inline)
		Matrix(const _RV* _array_, size_t _row_, size_t _column_)
	{
		_CopyForm_<_RV>(const_cast<_RV*>(_array_), _row_, _column_);
	}

	//用函数来初始化矩阵
	EasYMatrix_Head(inline)
		Matrix(std::function<_Pt(size_t, size_t)> _method_, size_t _row_, size_t _column_)
	{
		_NewForm_(_row_, _column_, _Default_, false);
		auto write_ptr = this->form;
		for (size_t i = 0; i < _row_; i++)
			for (size_t j = 0; j < _column_; j++)
				PtCast(*write_ptr++) = _method_(i, j);
	}

	EasYMatrix_Head(template<class _RV> inline)
		operator Matrix<_RV>()
	{
		Matrix<_RV> _result;
		_result._CopyForm_<_RV>(this->form, this->row, this->column);
		return _result;
	}

	//矩阵拷贝
	EasYMatrix_Head(EMSelf _NSelf) 
		Copy()
	{
		_NSelf _result = *this;
		return _result;
	}

	//其实只是交换了两者使用的地址
	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		Swap(Matrix<_RV>& _matrix_)
	{
		static_assert(sizeof(_RV) == sizeof(_Pt), "EasYMatrix - Swap - Type - Two types must be same size!\n");

		_Pt* temp_form = this->form;
		size_t temp_row = this->row,
			temp_column = this->column;

		this->form = reinterpret_cast<_Pt*>(_matrix_.form);
		this->row = _matrix_.row;
		this->column = _matrix_.column;

		_matrix_.form = reinterpret_cast<_RV*>(temp_form);
		_matrix_.row = temp_row;
		_matrix_.column = temp_column;

		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		Resize(size_t _row_, size_t _column_) noexcept
	{
		if constexpr (is_reference_wrapper_v<_Tt>)
		{
			_NewForm_(_row_, _column_, _Default_, false);
		}
		else
		{
			_NewForm_(_row_, _column_, _Default_);
		}
		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		Resize(size_t _row_, size_t _column_, const _Ty& _value_) noexcept
	{
		//引用类矩阵不能调用此函数
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - Resize - RMatrix can not be assgined to value!");

		_NewForm_(_row_, _column_, _value_);
		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		Reshape(size_t _row_, size_t _column_) noexcept
	{
		size_t _CapacityNeed = _row_ * _column_;
		if (_row_ > 0 && _column_ > 0)
		{
			//设置为新的行数和列数，分配新的内存空间
			size_t ori_size = row * column;
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
			{
				//记录原来的表和容量
				auto temp_form = this->form;
				size_t _cap = this->capacity;

				//重新分配内存
				this->form = nullptr;
				_Allocate_(_CapacityNeed);

				//只有当重新分配内存时进行拷贝
				auto write_ptr = this->form;
				auto read_ptr = temp_form;
				for (size_t i = 0; i < ori_size; i++)
					*write_ptr++ = *read_ptr++;

				//析构掉原来的form
				std::allocator<_Pt> alloc;
				auto des_ptr = temp_form + _cap;
				while (des_ptr != temp_form)
					alloc.destroy(--des_ptr);
				alloc.deallocate(temp_form, _cap);
			}
		}
		else
		{
			this->row = 0;
			this->column = 0;
		}

		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		Reshape(size_t _row_, size_t _column_, const _Ty& _value_) noexcept
	{
		//引用类矩阵不能调用此函数
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - Reshape - RMatrix can not be assgined to value!");

		//计算出多出来的部分有多大，然后 Reshape
		size_t new_size = _row_ * _column_;
		size_t ori_size = this->Size();
		size_t over_size = new_size > ori_size ? (new_size - ori_size) : 0;
		Reshape(_row_, _column_);

		//将多出来的部分用 _value_ 填充
		auto write_ptr = this->form + ori_size;
		for (size_t i = 0; i < over_size; i++)
			*write_ptr++ = _value_;

		return *this;
	}

	EasYMatrix_Head(EMSelf _Self&)
		SetValue(const _Ty& _value_) noexcept
	{
		auto write_ptr = form;
		size_t _size_ = row * column;

		//将所有元素设为同一个值
		for (size_t i = 0; i < _size_; i++)
			PtCast(*write_ptr++) = _value_;

		return *this;
	}

	EasYMatrix_Head(EMSelf _Self&)
		SetIdentity(size_t _dim_) noexcept
	{
		//禁止引用类型调用该函数
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - SetIdentity - RMatrix can not be changed to identity!");

		_NewForm_(_dim_, _dim_, _Default_, false);
		SetValue(_NSelf::_Zero_);

		auto write_ptr = form;
		size_t _row_add_ = 1 + _dim_;

		//对角线变为单位元
		for (size_t i = 0; i < _dim_; i++, write_ptr += _row_add_)
			*write_ptr = _NSelf::_Unit_;

		return *this;
	}

	EasYMatrix_Head(template<class _Pred> EMSelf _Self&)
		SetRandom(_Pred pf) noexcept
	{
		auto write_ptr = form;
		size_t _size_ = row * column;
		
		//每个元素都通过取随机数创建，注意 _Ty(rand()) 构造是否合法
		for (size_t i = 0; i < _size_; i++)
			PtCast(*write_ptr++) = _Ty(pf());

		return *this;
	}

	EasYMatrix_Head(inline EMSelf _Self&)
		Clear() noexcept
	{
		row = 0;
		column = 0;
	}

	EasYMatrix_Head(inline size_t)
		Memory() const noexcept
	{
		return sizeof(_Ty) * row * column;
	}

	EasYMatrix_Head(inline size_t)
		Rows() const noexcept
	{
		return row;
	}

	EasYMatrix_Head(inline size_t)
		Columns() const noexcept
	{
		return column;
	}

	EasYMatrix_Head(inline size_t)
		Size() const noexcept
	{
		return row * column;
	}

	EasYMatrix_Head(inline bool)
		Empty() const noexcept
	{
		return (form == nullptr);
	}

	EasYMatrix_Head(inline EMSelf _Ty&)
		operator()(size_t _row_, size_t _column_)
	{
		_DebugError_(_row_ >= row, "operator()", "Row is out of range!");
		_DebugError_(_column_ >= column, "operator()", "Column is out of range!");

		return form[_row_ * column + _column_];
	}

	EasYMatrix_Head(inline const EMSelf _Ty&)
		operator()(size_t _row_, size_t _column_) const
	{
		_DebugError_(_row_ >= row, "operator()", "Row is out of range!");
		_DebugError_(_column_ >= column, "operator()", "Column is out of range!");

		return form[_row_ * column + _column_];
	}

	EasYMatrix_Head(inline EMSelf _Ty&) 
		operator[](size_t _idx_)
	{
		_DebugError_(_idx_ >= row * column, "operator[]", "Index is out of range!");

		return form[_idx_];
	}

	EasYMatrix_Head(inline const EMSelf _Ty&) 
		operator[](size_t _idx_) const
	{
		_DebugError_(_idx_ >= row * column, "operator[]", "Index is out of range!");

		return form[_idx_];
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_)
	{
		bool row_all = std::find(_ip_.first.begin(), _ip_.first.end(), row) != _ip_.first.end();
		bool column_all = std::find(_ip_.second.begin(), _ip_.second.end(), column) != _ip_.second.end();

		if (row_all && column_all)
			return *this;
		if (row_all)
			return Column<_Rt>(_ip_.second.begin(), _ip_.second.size());
		if (column_all)
			return Row<_Rt>(_ip_.first.begin(), _ip_.first.size());
		return Row<_Rt>(_ip_.first.begin(), _ip_.first.size()).Column<_Rt>(_ip_.second.begin(), _ip_.second.size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_) const
	{
		bool row_all = std::find(_ip_.first.begin(), _ip_.first.end(), row) != _ip_.first.end();
		bool column_all = std::find(_ip_.second.begin(), _ip_.second.end(), column) != _ip_.second.end();

		if (row_all && column_all)
			return *this;
		if (row_all)
			return Column<_Ty>(_ip_.second.begin(), _ip_.second.size());
		if (column_all)
			return Row<_Ty>(_ip_.first.begin(), _ip_.first.size());
		return Row<_Ty>(_ip_.first.begin(), _ip_.first.size()).Column<_Ty>(_ip_.second.begin(), _ip_.second.size());
	}

	//用一个矩阵获取输出项
	template<class _Tt>
	template<class _RV, class _Mt>
	Matrix<_Mt> Matrix<_Tt>::_Index_(const Matrix<_RV>& _idx_matrix_) const
	{
		//判断行数与列数是否相同
		_DebugError_(this->row != _idx_matrix_.row, "operator()", "The row of two matrices must be same!");
		_DebugError_(this->column != _idx_matrix_.column, "operator()", "The column of two matrices must be same!");

		size_t id_count = _idx_matrix_.Size() - _idx_matrix_.Count(_idx_matrix_._Zero_);
		Matrix<_Mt> _result(id_count, 1);

		auto bool_read_ptr = _idx_matrix_.form;
		auto read_ptr = this->form;
		auto write_ptr = const_cast<_Mt*>(_result.form);
		size_t _size = this->Size();
		for (size_t i = 0; i < _size; i++, read_ptr++)
		{
			if (*bool_read_ptr++ != _idx_matrix_._Zero_)
			{
				if constexpr (is_reference_wrapper_v<_Mt>)
				{
					*write_ptr++ = *read_ptr;
				}
				else
				{
					*write_ptr++ = PtCast(*read_ptr);
				}
			}
		}

		return _result;
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _RSelf) 
		operator()(const Matrix<_RV>& _idx_matrix_)
	{
		return _Index_<_RV, _Rt>(_idx_matrix_);
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _NSelf)
		operator()(const Matrix<_RV>& _idx_matrix_, bool) const
	{
		return _Index_<_RV, _Ty>(_idx_matrix_);
	}

	//将矩阵中的非零元素用替换矩阵的元素按顺序替换
	EasYMatrix_Head(template<class _RV> auto)
		Take(const Matrix<_RV>& _rpl_matrix_) const
	{
		size_t rpl_leave = _rpl_matrix_.Size();
		size_t _my_size = Size();
		Matrix<typename remove_reference_wrapper<_RV>::type>
			result(this->row, this->column, Matrix<typename remove_reference_wrapper<_RV>::type>::_Zero_);

		auto ori_read_ptr = this->form;
		auto read_ptr = _rpl_matrix_.form;
		auto write_ptr = result.form;
		for (size_t i = 0; i < _my_size && rpl_leave; i++, write_ptr++)
		{
			//如果是非零元
			if (*ori_read_ptr++ != _NSelf::_Zero_)
			{
				//寻找替换项目
				PtCast(*write_ptr++) = *read_ptr++;
				rpl_leave--;
			}
		}

		return result;
	}

	//用另一个矩阵对该矩阵进行掩码
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		Mask(const Matrix<_RV>& _kernel_matrix_)
	{
		return Calculate<_RV>(_kernel_matrix_, 
			[&](_Tt& a, const _RV& b) {if (b == Matrix<_RV>::_NSelf::_Zero_) { PtCast(a) = _NSelf::_Zero_; }});
	}

	/*
	* 将矩阵的任意多行取出作为行向量组成一个新矩阵
	* 有先后顺序之分，比如输入参数 1 2 0 2 3 ，组成的新矩阵从上到下的行对应原矩阵也是 1 2 0 2 3
	* 
	* 这里因为用到参数包，所以第一步要先将参数包包装成数组，然后才能循环组成新矩阵
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		Row(const size_t* _index_list_, size_t _size_) const
	{
		Matrix<_RV> _result;
		if (_size_ > 0)
		{
			//创建新矩阵，准备复制
			_result._NewForm_(_size_, column, _Default_, false);

			auto write_ptr = _result.form;
			for (size_t i = 0; i < _size_; i++)
			{
				_DebugError_(_index_list_[i] >= row || column == 0, "Row", "Row is Out of range!");

				//将新矩阵当前行对应原矩阵目标行
				auto read_ptr = const_cast<_Pt*>(this->form) + _index_list_[i] * column;
				for (size_t j = 0; j < column; j++)
					*write_ptr++ = *read_ptr++;
			}
		}

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		Row(std::initializer_list<size_t> _multiple_index_)
	{
		return Row<_Rt>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		Row(std::initializer_list<size_t> _multiple_index_, bool) const
	{
		return Row<_Ty>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		Row(const Matrix<size_t>& _index_matrix_)
	{
		return Row<_Rt>(_index_matrix_.form, _index_matrix_.Size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		Row(const Matrix<size_t>& _index_matrix_, bool) const
	{
		return Row<_Ty>(_index_matrix_.form, _index_matrix_.Size());
	}

	/*
	* 与上面的行向量取出构成新矩阵同理
	* 这里将列向量取出构成新矩阵
	* 顺序为从左到右
	* 
	* 实现方法与行基本相同
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		Column(const size_t* _index_list_, size_t _size_) const
	{
		Matrix<_RV> _result;
		if (_size_ > 0)
		{
			//创建新矩阵，准备复制
			_result._NewForm_(row, _size_, _Default_, false);

			for (size_t i = 0; i < _size_; i++)
			{
				_DebugError_(_index_list_[i] >= column || row == 0, "Column", "Column is Out of range!");

				//将新矩阵当前列对应原矩阵目标列
				auto write_ptr = _result.form + i;
				auto read_ptr = const_cast<_Pt*>(this->form) + _index_list_[i];
				for (size_t j = 0; j < row; j++, write_ptr += _size_, read_ptr += column)
					*write_ptr = *read_ptr;
			}
		}

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		Column(std::initializer_list<size_t> _multiple_index_)
	{
		return Column<_Rt>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		Column(std::initializer_list<size_t> _multiple_index_, bool) const
	{
		return Column<_Ty>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		Column(const Matrix<size_t>& _index_matrix_)
	{
		return Column<_Rt>(_index_matrix_.form, _index_matrix_.Size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		Column(const Matrix<size_t>& _index_matrix_, bool) const
	{
		return Column<_Ty>(_index_matrix_.form, _index_matrix_.Size());
	}

	/*
	* 划去对应行，构成新矩阵
	* 可以输入重复的行，但是跟只输入一个效果是一样的
	*
	* 由于涉及到参数包，这里同样要先将参数包打包成数组
	* 然后将参数进行排序（这样方便后面给新矩阵赋值）
	*
	* 这里要反向考虑，因为我们不能分配完内存再“划掉”内存
	* 所以只能遍历所有行，看看该行是否能够分配（当然）
	* 这里的做法是先看看要划去多少行（实际上的）
	* 然后算出新矩阵的大小
	* 再屏蔽掉划去的行，用没屏蔽掉的行给新矩阵赋值
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		RowCrossOut(const size_t* _index_list_, size_t _size_) const
	{
		//需要新的数组
		std::allocator<size_t> alloc;
		size_t* new_index = alloc.allocate(_size_);

		//拷贝原数组
		auto copy_ptr = new_index;
		auto save_ptr = new_index;
		for (size_t i = 0; i < _size_; i++)
			*copy_ptr++ = *_index_list_++;

		//对数组进行排序，这里用的是快速排序
		std::sort(new_index, new_index + _size_);

		//这一步循环是看看实际上有多少行要被划去
		size_t _real_size_ = row;
		size_t _last_row_ = row;
		for (size_t i = 0; i < _size_; i++)
		{
			if (new_index[i] >= row)
			{
				_DebugError_(true, "RowCrossOut", "Row is Out of range!");
				break;
			}
			else if (new_index[i] == _last_row_)
			{
				continue;
			}
			else
			{
				_last_row_ = new_index[i];
				_real_size_--;
			}
		}

		Matrix<_RV> _result;
		if (_real_size_ > 0)
		{
			//创建新矩阵，准备复制
			_result._NewForm_(_real_size_, column, _Default_, false);

			auto write_ptr = _result.form;
			for (size_t i = 0; i < row; i++)
			{
				//被划去的行，将其屏蔽
				if (i == *new_index)
				{
					while (*++new_index == i);//这里使得参数能够填入重复的行，但是没有多余的作用
					continue;
				}

				//没屏蔽掉的行，进行复制
				auto read_ptr = this->form + i * column;
				for (size_t j = 0; j < column; j++)
					*write_ptr++ = *read_ptr++;
			}
		}

		//要把新构建的数组释放
		alloc.deallocate(save_ptr, _size_);

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		RowCrossOut(std::initializer_list<size_t>_multiple_index_)
	{
		return RowCrossOut<_Rt>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		RowCrossOut(std::initializer_list<size_t> _multiple_index_, bool) const
	{
		return RowCrossOut<_Ty>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		RowCrossOut(const Matrix<size_t>& _index_matrix_)
	{
		return RowCrossOut<_Rt>(_index_matrix_.form, _index_matrix_.Size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		RowCrossOut(const Matrix<size_t>& _index_matrix_, bool) const
	{
		return RowCrossOut<_Ty>(_index_matrix_.form, _index_matrix_.Size());
	}

	/*
	* 划去对应列，构成新矩阵
	* 可以输入重复的列，但是跟只输入一个效果是一样的
	*
	* 这里实现方法与划去行是一样的
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		ColumnCrossOut(const size_t* _index_list_, size_t _size_) const
	{
		//如果该数组不能被使用，需要新的数组
		std::allocator<size_t> alloc;
		size_t* new_index = alloc.allocate(_size_);

		//拷贝原数组
		auto copy_ptr = new_index;
		auto save_ptr = new_index;
		for (size_t i = 0; i < _size_; i++)
			*copy_ptr++ = *_index_list_++;

		//对数组进行排序，这里用的是快速排序
		std::sort(new_index, new_index + _size_);

		//看看实际上有多少列要被划去
		size_t _real_size_ = column;
		size_t _last_column_ = column;
		for (size_t i = 0; i < _size_; i++)
		{
			if (new_index[i] >= column)
			{
				_DebugError_(true, "ColumnCrossOut", "Column is Out of range!");
				break;
			}
			else if (new_index[i] == _last_column_)
			{
				continue;
			}
			else
			{
				_last_column_ = new_index[i];
				_real_size_--;
			}
		}

		Matrix<_RV> _result;
		if (_real_size_ > 0)
		{
			//创建新矩阵，准备复制
			_result._NewForm_(row, _real_size_, _Default_, false);

			size_t _temp_times_ = 0;//用于记录新矩阵复制到第几列
			for (size_t i = 0; i < column; i++)
			{
				//被划去的列，将其屏蔽
				if (i == *new_index)
				{
					while (*++new_index == i);
					continue;
				}

				//没屏蔽掉的列，进行复制
				auto write_ptr = _result.form + _temp_times_++;
				auto read_ptr = this->form + i;
				for (size_t j = 0; j < row; j++, write_ptr += _real_size_, read_ptr += column)
					*write_ptr = *read_ptr;
			}
		}

		//要把新构建的数组释放
		alloc.deallocate(save_ptr, _size_);

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		ColumnCrossOut(std::initializer_list<size_t> _multiple_index_)
	{
		return ColumnCrossOut<_Rt>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		ColumnCrossOut(std::initializer_list<size_t> _multiple_index_, bool) const
	{
		return ColumnCrossOut<_Ty>(_multiple_index_.begin(), _multiple_index_.size());
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		ColumnCrossOut(const Matrix<size_t>& _index_matrix_)
	{
		return ColumnCrossOut<_Rt>(_index_matrix_.form, _index_matrix_.Size());
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		ColumnCrossOut(const Matrix<size_t>& _index_matrix_, bool) const
	{
		return ColumnCrossOut<_Ty>(_index_matrix_.form, _index_matrix_.Size());
	}

	/*
	* 按矩形截取矩阵构成新矩阵
	* 参数需提供左上顶点的所在行、所在列以及右下顶点的所在行、所在列
	*
	* 实现方法即创建与截取部分同样大小的新矩阵
	* 复制过去即可
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>) SubMatrix(size_t _row_start_, size_t _row_end_,
		size_t _column_start_, size_t _column_end_) const
	{
		_DebugError_(_row_start_ >= row, "SubMatrix", "Row_Start is Out of range!");
		_DebugError_(_row_end_ > row, "SubMatrix", "Row_End is Out of range!");
		_DebugError_(_column_start_ >= column, "SubMatrix", "Column_Start is Out of range!");
		_DebugError_(_column_end_ > column, "SubMatrix", "Column_End is Out of range!");
		_DebugError_(_row_start_ >= _row_end_, "SubMatrix", "Illegal range of row!");
		_DebugError_(_column_start_ >= _column_end_, "SubMatrix", "Illegal range of column!");

		//创建新矩阵，准备复制
		Matrix<_RV> _result;
		_result.row = _row_end_ - _row_start_;
		_result.column = _column_end_ - _column_start_;
		_result._Allocate_(_result.row * _result.column);

		//将相应部分复制到新矩阵中
		auto read_ptr = const_cast<_Pt*>(&this->form[_row_start_ * column + _column_start_]);
		auto write_ptr = _result.form;
		size_t _row_add_ = column - _column_end_ + _column_start_;
		for (size_t i = 0; i < _result.row; i++, read_ptr += _row_add_)
			for (size_t j = 0; j < _result.column; j++)
				*write_ptr++ = *read_ptr++;

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		SubMatrix(size_t _row_end_, size_t _column_end_)
	{
		return SubMatrix(0, _row_end_, 0, _column_end_);
	}
	
	EasYMatrix_Head(inline EMSelf _RSelf)
		SubMatrix(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_)
	{
		return SubMatrix<_Rt>(_row_start_, _row_end_, _column_start_, _column_end_);
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		SubMatrix(size_t _row_end_, size_t _column_end_, bool) const
	{
		return SubMatrix(0, _row_end_, 0, _column_end_, true);
	}

	EasYMatrix_Head(inline EMSelf _NSelf)
		SubMatrix(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_, bool) const
	{
		return SubMatrix<_Ty>(_row_start_, _row_end_, _column_start_, _column_end_);
	}

	EasYMatrix_Head(inline EMSelf _RSelf) 
		operator()(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_)
	{
		return SubMatrix<_Rt>(_row_start_, _row_end_, _column_start_, _column_end_);
	}

	EasYMatrix_Head(inline EMSelf _NSelf) 
		operator()(size_t _row_start_, size_t _row_end_,
			size_t _column_start_, size_t _column_end_, bool _PLACEHOLDER_) const
	{
		return SubMatrix<_Ty>(_row_start_, _row_end_, _column_start_, _column_end_);
	}

	EasYMatrix_Head(inline EMSelf _RSelf)  
		operator()(_Ip _row_, _Ip _column_)
	{
		if (_row_.second < 0)
			_row_.second += row + 1;
		if (_column_.second < 0)
			_column_.second += column + 1;
		return SubMatrix<_Rt>(_row_.first, _row_.second, _column_.first, _column_.second);
	}

	EasYMatrix_Head(inline EMSelf _NSelf)  
		operator()(_Ip _row_, _Ip _column_, bool _PLACEHOLDER_) const
	{
		if (_row_.second < 0)
			_row_.second += row + 1;
		if (_column_.second < 0)
			_column_.second += column + 1;
		return SubMatrix<_Ty>(_row_.first, _row_.second, _column_.first, _column_.second);
	}

	/*
	* 实现矩阵的拼接，拼接方式有
	* | A B |   -
	*           A
	*           B
	*           -
	* 两种种方式（即左右、上下）
	* 这由第二个参数 left_right 控制（默认为true）
	* 
	* 实现方法仍为按大小构造新矩阵然后进行复制
	* 由 if 控制分支
	*/
	EasYMatrix_Head(template<class _Ty> Matrix<_Ty>)
		Splicing(const _Self& _matrix_, bool left_right) const
	{
		Matrix<_Ty> _result;
		auto read_ptr1 = const_cast<_Pt*>(this->form);
		auto read_ptr2 = const_cast<_Pt*>(_matrix_.form);

		if (left_right)
		{
			_DebugError_(row != _matrix_.row, "Splicing", "The row of two matrices must be same!");

			//左右拼接
			_result.Reshape(row, column + _matrix_.column);
			auto write_ptr = _result.form;
			
			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < this->column; j++)
					*write_ptr++ = *read_ptr1++;
				for (size_t j = 0; j < _matrix_.column; j++)
					*write_ptr++ = *read_ptr2++;
			}
		}
		else
		{
			_DebugError_(column != _matrix_.column, "Splicing", "The column of two matrices must be same!");

			//上下拼接
			_result.Reshape(row + _matrix_.row, column);
			auto write_ptr = _result.form;

			for (size_t i = 0; i < this->row; i++)
				for (size_t j = 0; j < column; j++)
					*write_ptr++ = *read_ptr1++;

			for (size_t i = 0; i < _matrix_.row; i++)
				for (size_t j = 0; j < column; j++)
					*write_ptr++ = *read_ptr2++;
		}

		return _result;
	}

	EasYMatrix_Head(inline EMSelf _RSelf)
		Splicing(_Self& _matrix_, bool left_right)
	{
		_DebugError_(this == &_matrix_, "Splicing", "Can not be spliced to matrix itself when using reference splicing!");

		return Splicing<_Rt>(_matrix_, left_right);
	}

	EasYMatrix_Head(inline EMSelf _NSelf) 
		Splicing(const _Self& _matrix_, bool left_right, bool) const
	{
		return Splicing<_Ty>(_matrix_, left_right);
	}

	//矩阵转置
	EasYMatrix_Head(EMSelf _NSelf)
		Transpose() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(column, row);

		auto write_ptr = _result.form;
		auto read_ptr = this->form;

		//颠倒行列进行赋值即可
		for (size_t i = 0; i < row; i++, write_ptr = _result.form + i)
			for (size_t j = 0; j < column; j++, write_ptr += row)
				*write_ptr = *read_ptr++;

		return _result;
	}

	//共轭转置
	EasYMatrix_Head(EMSelf _NSelf)
		ConjugateTranspose() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(column, row);

		auto write_ptr = _result.form;
		auto read_ptr = this->form;

		//颠倒行列进行赋值即可
		for (size_t i = 0; i < row; i++, write_ptr = _result.form + i)
		{
			for (size_t j = 0; j < column; j++, write_ptr += row)
			{
				if constexpr (std::is_same_v<_Ty, decltype(conj(*read_ptr))>)
				{
					*write_ptr = conj(*read_ptr++);
				}
				else
				{
					*write_ptr = *read_ptr++;
				}
			}
		}

		return _result;
	}

	//上下翻转
	EasYMatrix_Head(EMSelf _NSelf)
		FlipUpAndDown() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(row, column);

		//定位到最后一行
		auto write_ptr = _result.form + (row - 1) * column;
		auto read_ptr = this->form;

		//每次复制完跳到前一行
		for (size_t i = 0; i < row; i++, write_ptr -= (column + column))
			for (size_t j = 0; j < column; j++)
				*write_ptr++ = *read_ptr++;

		return _result;
	}

	//左右翻转
	EasYMatrix_Head(EMSelf _NSelf)
		FlipLeftAndRight() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(row, column);

		//定位到下一行
		auto write_ptr = _result.form + column;
		auto read_ptr = this->form;

		//每次复制完跳到后一行的后一行
		for (size_t i = 0; i < row; i++, write_ptr += (column + column))
			for (size_t j = 0; j < column; j++)
				*--write_ptr = *read_ptr++;

		return _result;
	}

	//逆时针旋转 n 个 90°
	EasYMatrix_Head(EMSelf _NSelf)
		Rotate90(int _n_) const
	{
		_n_ %= 4;
		if (_n_ < 0) _n_ += 4;

		if (form == nullptr || _n_ == 0)
			return _NSelf();

		_NSelf _result;
		auto read_ptr = this->form;

		switch (_n_)
		{
		case 1:
		{
			//逆时针旋转 1 个 90°
			_result.Reshape(column, row);

			//定位到最后一行
			auto help_ptr = _result.form + (column - 1) * row;
			auto write_ptr = help_ptr;

			//每次复制完跳到最后一行对应那个元素
			for (size_t i = 0; i < row; i++, write_ptr = ++help_ptr)
				//每次往前跳一行
				for (size_t j = 0; j < column; j++, write_ptr -= row)
					*write_ptr = *read_ptr++;

			break;
		}
		case 2:
		{
			//逆时针旋转 2 个 90°
			_result.Reshape(row, column);

			//定位到最后一个元素后
			auto write_ptr = _result.form + row * column;

			//倒序复制
			for (size_t i = 0; i < row; i++)
				for (size_t j = 0; j < column; j++)
					*--write_ptr = *read_ptr++;

			break;
		}
		case 3:
		{
			//逆时针旋转 3 个 90°
			_result.Reshape(column, row);

			//定位到第一行最后一个
			auto help_ptr = _result.form + (column - 1);
			auto write_ptr = help_ptr;

			//每次复制完跳到第一行对应那个元素
			for (size_t i = 0; i < row; i++, write_ptr = --help_ptr)
				//每次往后跳一行
				for (size_t j = 0; j < column; j++, write_ptr += row)
					*write_ptr = *read_ptr++;

			break;
		}
		}

		return _result;
	}

	/*
	* 对应比较矩阵的每个值
	* 满足为true，不满足为false
	*/
	template<class _Tt> template<class _RV, class _BL> BoolMatrix Matrix<_Tt>::
		Compare(const Matrix<_RV>& _matrix_, std::function<_BL(const _Tt&, const _RV&)> _method_) const
	{
		//判断行数与列数是否相同
		_DebugError_(this->row != _matrix_.row, "Compare", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Compare", "The column of two matrices must be same!");

		BoolMatrix result(row, column);

		//判断对应每个元素
		auto left_read_ptr = this->form;
		auto right_read_ptr = _matrix_.form;
		auto write_ptr = result.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _method_(*left_read_ptr++, *right_read_ptr++);

		return result;
	}

	template<class _Tt> template<class _RV, class _BL> BoolMatrix Matrix<_Tt>::
		Compare(const _RV& _value_, std::function<_BL(const _Tt&, const _RV&)> _method_) const
	{
		BoolMatrix result(row, column);

		//判断对应每个元素
		auto read_ptr = this->form;
		auto write_ptr = result.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _method_(*read_ptr++, _value_);

		return result;
	}

	//等于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator==(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a == b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator==(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a == b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator==(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ == _value_;
	}

	//不等于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator!=(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a != b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator!=(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a != b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator!=(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ != _value_;
	}

	//大于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator>(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a > b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator>(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a > b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator>(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ < _value_;
	}

	//小于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator<(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a < b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator<(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a < b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator<(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ > _value_;
	}

	//大于等于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator>=(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a >= b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator>=(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a >= b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator>=(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ <= _value_;
	}

	//小于等于
	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator<=(const Matrix<_RV>& _matrix_) const
	{
		return Compare<_RV, bool>(_matrix_, [](const _Tt& a, const _RV& b)->bool {return a <= b; });
	}

	EasYMatrix_Head(template<class _RV> inline BoolMatrix)
		operator<=(const _RV& _value_) const
	{
		return Compare<_RV, bool>(_value_, [](const _Tt& a, const _RV& b)->bool {return a <= b; });
	}

	template<class _Ty, class _RV>
	inline BoolMatrix operator<=(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ >= _value_;
	}

	//令矩阵的某一项与另外一个矩阵的对应项进行运算
	EasYMatrix_Head (template<class _RV> EMSelf _Self&)
		Calculate(const Matrix<_RV>& _matrix_, std::function<void(_Pt&, const _RV&)> _method_)
	{
		//判断行数与列数是否相同
		_DebugError_(this->row != _matrix_.row, "Calculate", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Calculate", "The column of two matrices must be same!");

		//遍历运算
		auto write_ptr = this->form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++, *read_ptr++);

		return *this;
	}

	//令矩阵的某一项与一个数进行计算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		Calculate(const _RV& _value_, std::function<void(_Pt&, const _RV&)> _method_)
	{
		//遍历运算
		auto write_ptr = this->form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++, _value_);

		return *this;
	}

	//令矩阵的每一项进行一种运算 - 自运算
	EasYMatrix_Head(EMSelf _Self&)
		Calculate(std::function<void(_Pt&)> _method_)
	{
		//令每一项进行一种运算
		auto write_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++);
		return *this;
	}

	//计数函数 - 遍历矩阵的每一项，计算出一个结果
	EasYMatrix_Head(template<class _RV> _RV)
		Count(_RV _original_value_, std::function<void(_RV&, const _Ty&)> _method_) const
	{
		auto read_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++)
			_method_(_original_value_ , *read_ptr++);
		return _original_value_;
	}

	//计数函数 - 获取矩阵中某一项的个数
	EasYMatrix_Head(size_t) 
		Count(const _Ty& _value_) const
	{
		return Count<size_t>(0, [&](size_t& i, const _Pt& j) {if (j == _value_)i++; });
	}

	//与运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator&=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Pt& a, const _RV& b) {PtCast(a) &= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator&(const Matrix<_RV>& _matrix_)
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() & typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		_result &= _matrix_;
		return _result;
	}

	//或运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator|=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Pt& a, const _RV& b) {PtCast(a) |= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator|(const Matrix<_RV>& _matrix_)
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() | typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		_result |= _matrix_;
		return _result;
	}

	//异或运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator^=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Pt& a, const _RV& b) {PtCast(a) ^= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator^(const Matrix<_RV>& _matrix_)
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() ^ typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		_result ^= _matrix_;
		return _result;
	}

	//数量与运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator&=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {PtCast(a) &= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator&(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()& typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result &= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator&(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ & _value_;
	}

	//数量或运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator|=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {a |= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator|(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() | typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result |= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator|(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ | _value_;
	}

	//数量异或运算
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator^=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {a ^= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator^(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() ^ typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result ^= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator^(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ ^ _value_;
	}

	//矩阵取非
	EasYMatrix_Head(EMSelf _NSelf)
		operator!() const
	{
		//拷贝
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = !a; });
		return _result;
	}

	//矩阵取负
	EasYMatrix_Head(EMSelf _NSelf)
		operator-() const
	{
		//拷贝
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = -a; });
		return _result;
	}

	//矩阵取共轭
	EasYMatrix_Head(EMSelf _NSelf)
		operator~() const
	{
		//拷贝
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = conj(a); });
		return _result;
	}

	/*
	* 矩阵加法
	* 遍历 form 对应相加
	*/
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator+=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a += b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator+(const Matrix<_RV>& _matrix_) const
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() + typename remove_reference_wrapper<_RV>::type())> 
			_result = *this;
		return _result += _matrix_;
	}

	/*
	* 矩阵减法
	* 遍历 form 对应相减
	*/
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator-=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a -= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator-(const Matrix<_RV>& _matrix_) const
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() - typename remove_reference_wrapper<_RV>::type())> 
			_result = *this;
		return _result -= _matrix_;
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		operator*=(const Matrix<_RV>& _matrix_)
	{
		*this = *this * _matrix_;
		return *this;
	}

	/*
	* 矩阵乘法
	* 这里跟加减法不同，要用到三次循环（因为根据定义每一项又是一个求和）
	*/
	EasYMatrix_Head(template<class _RV> inline auto)
		operator*(const Matrix<_RV>& _matrix_) const
	{
		_DebugError_(this->column != _matrix_.row, "operator*", "Left matrix's column is not equal to right matrix's row!");

		//创建新矩阵
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>
			_result(this->row, _matrix_.column, 
				Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>::_Zero_);
		
		//求出新矩阵的每一项
		auto write_ptr = _result.form;
		auto left_read_ptr = this->form;
		auto right_read_ptr = _matrix_.form;
		for (size_t i = 0; i < this->row; i++, right_read_ptr = _matrix_.form, write_ptr += _result.column)
			for (size_t k = 0; k < this->column; k++, left_read_ptr++, write_ptr -= _result.column)
				for (size_t j = 0; j < _matrix_.column; j++)
					*write_ptr++ += PtCast(*left_read_ptr) * _matrix_.PtCast(*right_read_ptr++);	//矩阵乘法定义

		return _result;
	}

	//矩阵内积
	EasYMatrix_Head(template<class _RV> inline auto)
		operator%(const Matrix<_RV>& _matrix_) const
	{
		_DebugError_(this->row != _matrix_.row, "Dot Product", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Dot Product", "The column of two matrices must be same!");

		//将结果先设成零元
		decltype(typename remove_reference_wrapper<_Tt>::type() * typename remove_reference_wrapper<_RV>::type())
			_result =
			std::is_same<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type()),
			typename remove_reference_wrapper<_Tt>::type>::value ?
			_NSelf::_Zero_ : Matrix<_RV>::_NSelf::_Zero_;

		//遍历求内积
		auto left_read_ptr = this->form;
		auto right_read_ptr = _matrix_.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
		{
			if constexpr (IsComplex_<decltype(_result)>::value)
			{
				_result += conj(PtCast(*left_read_ptr++)) * _matrix_.PtCast(*right_read_ptr++);
			}
			else
			{
				_result += PtCast(*left_read_ptr++) * _matrix_.PtCast(*right_read_ptr++);
			}
		}
		
		return _result;
	}

	//矩阵数量加法
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator+=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a += b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator+(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() + typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result += _value_;
	}

	template<class _Ty,class _RV> 
	inline auto operator+(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ + _value_;
	}
	
	//矩阵数量减法
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator-=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a -= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator-(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() - typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result -= _value_;
	}

	template<class _Ty, class _RV>
	auto operator-(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//准备好内存空间
		Matrix<decltype(_Ty() + _RV())> _result(_matrix_.row, _matrix_.column);

		//遍历相减
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_  - *read_ptr++;

		return _result;
	}

	//矩阵数量乘法
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator*=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a *= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator*(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result *= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator*(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ * _value_;
	}

	//矩阵数量除法
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator/=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a /= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator/(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() / typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result /= _value_;
	}

	template<class _Ty, class _RV>
	auto operator/(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//准备好内存空间
		Matrix<decltype(_RV() / _Ty())> _result(_matrix_.row, _matrix_.column);

		//遍历相除
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_ / *read_ptr++;

		return _result;
	}

	//矩阵数量取余
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator%=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a %= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator%(const _RV& _value_) const
	{
		//准备好内存空间
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() % typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result %= _value_;
	}

	template<class _Ty, class _RV>
	auto operator%(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//准备好内存空间
		Matrix<decltype(_RV() % _Ty())> _result(_matrix_.row, _matrix_.column);

		//遍历取余
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_ % *read_ptr++;

		return _result;
	}

	//矩阵逐项相乘
	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		Mutiply(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a *= b; });
	}

	template<class _Tt, class _RV>
	inline auto Mutiply(const Matrix<_Tt>& _matrix1_, const Matrix<_RV>& _matrix2_)
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() * typename remove_reference_wrapper<_RV>::type())>
			_result = _matrix1_;
		return _result.Mutiply(_matrix2_);
	}

	//矩阵逐项相除
	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		operator/=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a /= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator/(const Matrix<_RV>& _matrix_) const
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() / typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result /= _matrix_;
	}

	//矩阵逐项相余
	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		operator%=(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a %= b; });
	}

	EasYMatrix_Head(template<class _RV> inline EMSelf _Self&)
		Surplus(const Matrix<_RV>& _matrix_)
	{
		return Calculate<_RV>(_matrix_, [](_Ty& a, const _RV& b) {a %= b; });
	}

	template<class _Tt, class _RV>
	inline auto Surplus(const Matrix<_Tt>& _matrix1_, const Matrix<_RV>& _matrix2_)
	{
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() % typename remove_reference_wrapper<_RV>::type())>
			_result = _matrix1_;
		return _result %= _matrix2_;
	}

	//交换两行
	EasYMatrix_Head(EMSelf _Self&)
		RowExchange(size_t _row1_, size_t _row2_)
	{
		_DebugError_(_row1_ >= row || _row2_ >= row, "RowExchange", "The row is out of range!");

		if (_row1_ == _row2_)return *this;

		auto row1_ptr = form + _row1_ * column;
		auto row2_ptr = form + _row2_ * column;
		_Ty temp;

		for (size_t i = 0; i < column; i++, row1_ptr++, row2_ptr++)
		{
			temp = PtCast(*row1_ptr);
			PtCast(*row1_ptr) = PtCast(*row2_ptr);
			PtCast(*row2_ptr) = temp;
		}

		return *this;
	}

	//交换两列
	EasYMatrix_Head(EMSelf _Self&)
		ColumnExchange(size_t _column1_, size_t _column2_)
	{
		_DebugError_(_column1_ >= column || _column2_ >= column, "ColumnExchange", "The column is out of range!");

		if (_column1_ == _column2_)return *this;

		auto column1_ptr = form + _column1_;
		auto column2_ptr = form + _column2_;
		_Ty temp;

		for (size_t i = 0; i < row; i++, column1_ptr += column, column2_ptr += column)
		{
			temp = PtCast(*column1_ptr);
			PtCast(*column1_ptr) = PtCast(*column2_ptr);
			PtCast(*column2_ptr) = temp;
		}

		return *this;
	}

	//让某行乘上一个数
	EasYMatrix_Head(EMSelf _Self&)
		RowMultiply(size_t _row_, const _Ty& _value_)
	{
		_DebugError_(_row_ >= row, "RowMultiply", "The row is out of range!");

		if (_value_ == _NSelf::_Unit_)return *this;

		auto row_ptr = form + _row_ * column;
		if(_value_ == _NSelf::_Zero_)
			for (size_t i = 0; i < column; i++)
				PtCast(*row_ptr++) = _NSelf::_Zero_;
		else
			for (size_t i = 0; i < column; i++)
				PtCast(*row_ptr++) *= _value_;

		return *this;
	}

	//让某列乘上一个数
	EasYMatrix_Head(EMSelf _Self&)
		ColumnMultiply(size_t _column_, const _Ty& _value_)
	{
		_DebugError_(_column_ >= column, "ColumnMultiply", "The column is out of range!");

		if (_value_ == _NSelf::_Unit_)return *this;

		auto column_ptr = form + _column_;
		if (_value_ == _NSelf::_Zero_)
			for (size_t i = 0; i < row; i++, column_ptr +=column)
				PtCast(*column_ptr) = _NSelf::_Zero_;
		else
			for (size_t i = 0; i < row; i++, column_ptr += column)
				PtCast(*column_ptr) *= _value_;

		return *this;
	}

	//让某行加上某行的任意倍
	//注：是 row1 加上 value 倍的 row2
	EasYMatrix_Head(EMSelf _Self&)
		RowAdd(size_t _row1_, size_t _row2_, const _Ty& _value_)
	{
		_DebugError_(_row1_ >= row || _row2_ >= row, "RowAdd", "The row is out of range!");

		if (_value_ == _NSelf::_Zero_)return *this;

		auto row1_ptr = form + _row1_ * column;
		auto row2_ptr = form + _row2_ * column;
		if(_value_ == _NSelf::_Unit_)
			for (size_t i = 0; i < column; i++)
				PtCast(*row1_ptr++) += *row2_ptr++;
		else
			for (size_t i = 0; i < column; i++)
				PtCast(*row1_ptr++) += _value_ * PtCast(*row2_ptr++);

		return *this;
	}

	//让某列加上某行的任意倍
	//注：是 column1 加上 value 倍的 column2
	EasYMatrix_Head(EMSelf _Self&)
		ColumnAdd(size_t _column1_, size_t _column2_, const _Ty& _value_)
	{
		_DebugError_(_column1_ >= column || _column2_ >= column, "ColumnAdd", "The column is out of range!");

		if (_value_ == _NSelf::_Zero_)return *this;

		auto column1_ptr = form + _column1_;
		auto column2_ptr = form + _column2_;
		if (_value_ == _NSelf::_Unit_)
			for (size_t i = 0; i < row; i++, column1_ptr += column, column2_ptr += column)
				PtCast(*column1_ptr) += *column2_ptr;
		else
			for (size_t i = 0; i < row; i++, column1_ptr += column, column2_ptr += column)
				PtCast(*column1_ptr) += _value_ * PtCast(*column2_ptr);

		return *this;
	}

	//计算矩阵的迹
	EasYMatrix_Head(EMSelf _Ty)
		Trace() const
	{
		_DebugError_(row != column, "Trace", "The matrix must be square!");

		auto _ptr = form;
		size_t _offs = row + 1;
		_Ty result = _NSelf::_Zero_;

		for (size_t i = 0; i < row; i++, _ptr += _offs)
			result += *_ptr;

		return result;
	}

	//计算矩阵的绝对值的迹
	EasYMatrix_Head(auto)
		AbsoluteTrace() const
	{
		_DebugError_(row != column, "AbsoluteTrace", "The matrix must be square!");

		auto _ptr = form;
		size_t _offs = row + 1;
		auto result = decltype(abs(std::declval<_Ty>()))();

		for (size_t i = 0; i < row; i++, _ptr += _offs)
			result += abs(*_ptr);

		return result;
	}

	//计算矩阵的对角积
	EasYMatrix_Head(EMSelf _Ty) 
		Diagonal() const
	{
		_DebugError_(row != column, "Diagonal", "The matrix must be square!");

		auto _ptr = form;
		size_t _offs = row + 1;
		_Ty result = _NSelf::_Unit_;

		for (size_t i = 0; i < row; i++, _ptr += _offs)
			result *= *_ptr;

		return result;
	}

	//计算矩阵的行列式的值
	EasYMatrix_Head(EMSelf _Ty) 
		Determinant() const
	{
		_DebugError_(row != column, "Determinant", "The matrix must be square!");

		//原理
		//通过高斯消元将行列式化为上三角形
		//则行列式值就是对角线乘积

		_NSelf Det = *this;
		Det.GaussianElimination();
		return Det.Diagonal();
	}

	//求矩阵的逆矩阵
	EasYMatrix_Head(EMSelf _NSelf)
		Inverse() const
	{
		_DebugError_(row != column, "Inverse", "The matrix must be square!");

		//原理
		//构造 B = [A I]
		//通过高斯约旦消元法化成 C = [I H]
		//其中 H 便是 A 的逆矩阵

		//第一步 - 拼接矩阵 B
		_NSelf I, A;
		I.SetIdentity(row);
		A = *this;
		auto B = A.Splicing(I);
		
		//第二步 - 对矩阵 B 进行 高斯约旦消元
		B.GaussJordanElimination();

		return I;
	}

	//阈值函数
	//到某点的模值小于阈值的元素置为该点的值
	EasYMatrix_Head(EMSelf _Self&)
		Threshold(std::initializer_list<_Ty> points, const decltype(norm(std::declval<_Ty>()))& thresh_val)
	{
		auto temp_form = this->form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++, temp_form++)
			for(auto& j : points)
				if (norm(PtCast(*temp_form) - j) / norm(j) < thresh_val * thresh_val)
					PtCast(*temp_form) = j;
		return *this;
	}

	//自动阈值函数
	//去除过小的 实部 或 虚部
	EasYMatrix_Head(EMSelf _Self&)
		AutoThreshold(const decltype(norm(std::declval<_Ty>()))& thresh_val)
	{
		auto temp_form = this->form;
		size_t _size_ = row * column;
		if constexpr (IsComplex_<_Ty>::value)
		{
			//复数去除过小值，过小实部或虚部
			for (size_t i = 0; i < _size_; i++, temp_form++)
			{
				auto norm_v = norm(PtCast(*temp_form));
				if (norm_v < thresh_val * thresh_val)
				{
					PtCast(*temp_form) = _NSelf::_Zero_;
				}
				else if (norm(imag(PtCast(*temp_form))) / norm_v < thresh_val * thresh_val)
				{
					PtCast(*temp_form).imag(decltype(PtCast(*temp_form).imag())());
				}
				else if(norm(real(PtCast(*temp_form))) / norm_v < thresh_val * thresh_val)
				{
					PtCast(*temp_form).real(decltype(PtCast(*temp_form).real())());
				}
			}
		}
		else
		{
			//实数只去除过小值
			for (size_t i = 0; i < _size_; i++, temp_form++)
			{
				auto norm_v = norm(PtCast(*temp_form));
				if (norm_v < thresh_val * thresh_val)
					PtCast(*temp_form) = _NSelf::_Zero_;
			}
		}
		return *this;
	}

	//求矩阵的 Frobenius 范数
	EasYMatrix_Head(auto)
		FrobeniusNorm() const
	{
		using T = decltype(abs(std::declval<_Ty>()));
		T result = T();

		//获取缩放倍数
		auto scaling_coe = ScalingCoefficient();

		//所有元素的平方和
		auto read_ptr = this->form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			result += norm(PtCast(*read_ptr) * scaling_coe);

		//开方
		return sqrt(result) / scaling_coe;
	}

	//求矩阵的 无穷-范数
	EasYMatrix_Head(auto)
		InfiniteNorm() const
	{
		using T = decltype(abs(std::declval<_Ty>()));
		T max = T(), temp;
		auto read_ptr = this->form;
		for (size_t i = 0; i < row; i++)
		{
			temp = T();
			for (size_t j = 0; j < column; j++, read_ptr++)
			{
				//保证加的是绝对值
				temp += abs(*read_ptr);
			}

			//保证取最大的
			if (abs(temp) > abs(max))
				max = temp;
		}
		return max;
	}

	//求矩阵的 1-范数
	EasYMatrix_Head(auto)
		OneNorm() const
	{
		using T = decltype(abs(std::declval<_Ty>()));
		T max = T(), temp;
		const _Ty* y = nullptr;
		for (size_t j = 0; j < column; j++)
		{
			temp = T();
			for (size_t i = 0; i < row; i++)
			{
				y = &(*this)(i, j);

				//保证加的是绝对值
				temp += abs(*y);
			}

			//保证取最大的
			if (abs(temp) > abs(max))
				max = temp;
		}
		return max;
	}

	//求矩阵的 2-范数
	EasYMatrix_Head(auto)
		TwoNorm(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		return sqrt(real((this->ConjugateTranspose() * (*this)).PowerMethod(max_error)));
	}

	//求矩阵的最大特征值的模
	//用的是幂法
	EasYMatrix_Head(EMSelf _Ty)
		PowerMethod(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "PowerMethod", "The matrix must be square!");

		_NSelf xn(column, 1, _NSelf::_Unit_);
		_Ty last_dist_v = _NSelf::_Unit_ + _NSelf::_Unit_,
			dist_v = _NSelf::_Unit_;

		//误差小于一定值才停止循环
		while (norm(_NSelf::_Unit_ - dist_v / last_dist_v) > max_error * max_error)
		{
			last_dist_v = dist_v;
			xn = (*this) * xn;
			dist_v = xn.InfiniteNorm();
			xn /= dist_v;
		}

		return dist_v;
	}

	//求矩阵的最大特征值的模
	//用的是瑞利商迭代
	EasYMatrix_Head(EMSelf _Ty)
		RayleighQuotientIteration(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "RayleighQuotientIteration", "The matrix must be square!");

		_NSelf xn(column, 1, _NSelf::_Unit_), MA;
		_RSelf MB;
		_Ty last_dist_v = _NSelf::_Unit_ + _NSelf::_Unit_,
			dist_v = _NSelf::_Unit_;

		//误差小于一定值才停止循环
		while (norm(_NSelf::_Unit_ - dist_v / last_dist_v) > max_error * max_error)
		{
			//迭代，计算位移量
			last_dist_v = dist_v;
			dist_v = xn % ((*this) * xn) / (xn % xn);

			//求解方程组
			MA = (*this) - dist_v * _NSelf().SetIdentity(row);
			MB = MA.Splicing(xn);
			MB.GaussJordanElimination();

			//得到新的结果
			xn /= xn.InfiniteNorm();
		}

		return dist_v;
	}

	//获取雅可比旋转矩阵
	EasYMatrix_Head(EMSelf _NSelf)
		JacobiMatrix(size_t idx1, size_t idx2)
	{
		_DebugError_(std::max(idx1, idx2) >= std::min(row, column), "JacobiMatrix", "Index is out of range!");

		//计算前置参数
		_Ty tau = ((*this)(idx1, idx1) - (*this)(idx2, idx2)) / ((*this)(idx1, idx2) + (*this)(idx2, idx1));
		_Ty t = tau == _NSelf::_Zero_ ? _NSelf::_Unit_ : (tau / (abs(tau) * (abs(tau) + sqrt(_NSelf::_Unit_ + tau * tau))));
		_Ty cos_v = _NSelf::_Unit_ / sqrt(_NSelf::_Unit_ + t * t), sin_v = t * cos_v;

		//生成雅可比旋转矩阵
		_NSelf jacobi_mat(2, 2);
		if constexpr (IsComplex_<_Ty>::value)
		{
			jacobi_mat(0, 0) = conj(cos_v);
			jacobi_mat(0, 1) = conj(sin_v);
		}
		else
		{
			jacobi_mat(0, 0) = cos_v;
			jacobi_mat(0, 1) = sin_v;
		}
		jacobi_mat(1, 0) = -sin_v;
		jacobi_mat(1, 1) = cos_v;

		//复矩阵还要正交化
		if constexpr (IsComplex_<_Ty>::value)
			jacobi_mat *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return jacobi_mat;
	}

	//雅可比旋转
	//限定：对称矩阵
	EasYMatrix_Head(EMSelf _Self&) 
		JacobiRotatation(size_t idx1, size_t idx2, _NSelf* eig_vecs)
	{
		_DebugError_(std::max(idx1, idx2) >= std::min(row, column), "JacobiRotatation", "Index is out of range!");

		//生成雅可比矩阵
		_NSelf jacobi_mat = JacobiMatrix(idx1, idx2);
		
		//1.行变换 - 左乘
		GivensLeft(jacobi_mat, idx1, idx2);

		//2.列变换 - 右乘
		GivensRight(jacobi_mat.ConjugateTranspose(), idx1, idx2);

		//3.特征向量矩阵处理（如果存在）
		if (eig_vecs)
			_DebugError_(std::max(idx1, idx2) >= std::min(eig_vecs->row, eig_vecs->column), "JacobiRotatation", "Index is out of range!(For eig_vecs)"),
			eig_vecs->GivensRight(jacobi_mat.ConjugateTranspose(), idx1, idx2);

		return *this;
	}

	//双边雅可比方法
	//求出矩阵的全部特征值
	//限定：对称矩阵（注意：非对称矩阵会陷入死循环！）
	EasYMatrix_Head(EMSelf _NSelf)  
		BilateralJacobiMethod(_NSelf* eig_vecs, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		//检查是否为对称阵
		//检查对角元素是否为0
#ifdef _DEBUG
		_DebugError_(row != column, "JacobiMethod", "The matrix must be square!");
		{
			for (size_t i = 0; i < row; i++)
				for (size_t j = (i + 1); j < column; j++)
					if(abs((*this)(i,j) - (*this)(j,i)) > max_error)
#ifdef _IOSTREAM_
						std::cerr << "EasYMatrix - JacobiMethod - The matrix is asymmetric within the error range!\n"
						<< "The ("<< i << "," << j << ") is " << (*this)(i, j)
						<< ".\nThe (" << j << "," << i << ") is " << (*this)(j, i) << "." << std::endl,
#endif
						throw max_error;

			for (size_t i = 0; i < row; i++)
				if ((*this)(i, i) == _NSelf::_Zero_)
#ifdef _IOSTREAM_
					std::cerr << "EasYMatrix - JacobiMethod - Diagonal elements can not be zero!\n"
					<< "The (" << i << "," << i << ") is " << (*this)(i, i) << "." << std::endl,
#endif
					throw (*this)(i, i);
		}
#endif
		_NSelf result = *this;
		size_t dim = row;
		_Ty scaling_coe;

		//如果要获取特征向量，先变为单位矩阵
		if (eig_vecs)
			eig_vecs->SetIdentity(dim);

		//进行缩放
		result.Normalization(&scaling_coe);
		//进行遍历旋转
		bool had_find = false;
		do
		{
			had_find = false;

			for (size_t i = 0; i < (dim - 1); i++)
			{
				for (size_t j = (i + 1); j < dim; j++)
				{
					//数值过大，进行旋转
					if (abs(result(i, j)) > max_error)
					{
						had_find = true;
						result.JacobiRotatation(i, j, eig_vecs);
					}
				}
			}

			//旋转过继续迭代旋转
		} while (had_find);

		//全部在精度范围内，跳出循环，把误差量消去
		result.AutoThreshold(max_error);

		//放大回去
		return result *= _NSelf::_Unit_ / scaling_coe;
	}

	//求特征值及特征向量
	EasYMatrix_Head(EMSelf _CSelf)
		Eigvalues(_CSelf* eig_vecs, const decltype(norm(std::declval<_Ty>()))& max_error)
	{
		_DebugError_(row != column, "Eigvalues", "The matrix must be square!");

		const size_t dim = this->row;

		_CSelf result = *this;
		result.SchurDecomposition(result, eig_vecs, max_error);

		if (eig_vecs)
		{
			//计算特征向量 利用 U 和 T
			//求 T = X * D * X^(-1)
			//有 A = U * T * T^(-1) = (U * X) * D * (U * X)^(-1)
			//X 的求法：T列变换同时D行变换，最终变成 T * X = X * D
			//这段是照搬 Eigen 库里面的
			_CSelf m_matX(dim, dim, _CSelf::_Zero_);
			for (int64_t k = dim - 1; k >= 0; k--)
			{
				m_matX(k, k) = _CSelf::_Unit_;
				for (int64_t i = k - 1; i >= 0; i--)
				{
					m_matX(i, k) = -result(i, k);
					if (k - i - 1 > 0)
						m_matX(i, k) -= (result.SubMatrix(i, i + 1, i + 1, k) * m_matX.SubMatrix(i + 1, k, k, k + 1))[0];
					_Ct z = result(i, i) - result(k, k);
					if (z == _CSelf::_Zero_)
						z = max_error;
					m_matX(i, k) = m_matX(i, k) / z;
				}
			}

			*eig_vecs *= m_matX;

			_CRSelf temp;
			for (size_t i = 0; i < dim; i++)
			{
				temp = eig_vecs->Column({ i });
				temp *= _CSelf::_Unit_ / temp.FrobeniusNorm();
			}
		}

		//获取特征值矩阵
		for (size_t i = 0; i < dim; i++)
			for (size_t j = i + 1; j < dim; j++)
				result(i, j) = _CSelf::_Zero_;

		return result;
	}

	//让矩阵进行高斯消元
	//采用的是部分主元消去法
	EasYMatrix_Head(EMSelf _Self&)
		GaussianElimination()
	{
		//获取矩阵某一行的首元素所在位置
		auto get_first_of_row = [&](size_t _row_) -> size_t
		{
			for (size_t i = 0; i < this->Columns(); i++)
				if ((*this)(_row_, i) != _NSelf::_Zero_)
					return i;
			return this->Columns();
		};
		
		//将矩阵变换为阶梯型矩阵
		size_t skip_cols = 0;
		for (size_t i = 0; i < this->Rows() - 1; i++)
		{
			//保证当前行的首元素是在下面所有行中的最前面
			size_t now_first = get_first_of_row(i);
			if (now_first > i + skip_cols)
			{
				//寻找元素比自己更前的
				size_t best_row = i;
				size_t best_first = now_first;
				for (size_t j = i + 1; j < this->Rows(); j++)
				{
					size_t this_first = get_first_of_row(j);
					if (this_first == this->Columns()) continue;	//防止索引错误 this_first 报错
					if (this_first < best_first ||
						(this_first == best_first && 
							norm((*this)(j, this_first)) > norm((*this)(best_row, best_first))))
					{
						best_row = j;
						best_first = this_first;
					}
				}

				//跟比自己前的换行
				now_first = best_first;
				skip_cols = now_first - i;
				this->RowExchange(i, best_row);
			}

			//如果都是全为0，跳出循环
			if (now_first == this->Columns())
				break;

			//减掉下面行该列的元素
			_Ty _tempv_ = _NSelf::_Unit_ / (*this)(i, now_first);
			for (size_t j = i + 1; j < this->Rows(); j++)
			{
				this->RowAdd(j, i, -_tempv_ * (*this)(j, now_first));
				(*this)(j, now_first) = _NSelf::_Zero_;
			}
		}

		return *this;
	}

	//让矩阵进行高斯若当消元
	EasYMatrix_Head(EMSelf _Self&)
		GaussJordanElimination()
	{
		//获取矩阵某一行的首元素所在位置
		auto get_first_of_row = [&](size_t _row_) -> size_t
		{
			for (size_t i = 0; i < this->Columns(); i++)
				if ((*this)(_row_, i) != _NSelf::_Zero_)
					return i;
			return this->Columns();
		};

		//第一步 - 进行高斯消元
		this->GaussianElimination();

		//第二步 - 将每一行首元素置1
		size_t i = 0;
		size_t _col_;
		for (; i < this->Rows(); i++)
		{
			_col_ = get_first_of_row(i);
			if (_col_ != this->Columns())
			{
				this->RowMultiply(i, _NSelf::_Unit_ / (*this)(i, _col_));
			}
			else
			{
				break;
			}
		}
		i--;

		//第三步 - 化为最终的高斯消元矩阵
		for (; i > 0; i--)
		{
			for (size_t j = 0; j < i; j++)
			{
				_col_ = get_first_of_row(i);
				this->RowAdd(j, i, -(*this)(j, _col_));
				(*this)(j, _col_) = _NSelf::_Zero_;
			}
		}

		return *this;
	}

	//让矩阵进行 LU 分解
	EasYMatrix_Head(void)
		LUDecomposition(_NSelf& _Linv_, _NSelf& _U_) const
	{
		//原理
		//求 LU = A
		//构造矩阵 B = [A I] = [LU I]
		//对B进行高斯消元可得 C = [U L-1]

		//第一步 - 构造 B
		_Linv_.SetIdentity(this->Rows());
		_U_ = *this;
		_RSelf B = _U_.Splicing(_Linv_);

		//第二步 - 高斯消元
		B.GaussianElimination();
	}

	//Gram - Schmidt 正交化 （对列向量）
	//采用的是改进版本的
	EasYMatrix_Head(EMSelf _Self&)
		GramSchmidtOrthogonalization(_NSelf* _R_, size_t _column_start_)
	{
		_DebugError_(_column_start_ > column, "GramSchmidtOrthogonalization", "The column_start is out of range!");

		if (_R_) _R_->Reshape(column, column, _NSelf::_Zero_);
		_RSelf result_col, back_col;
		_Ty norm_v;

		//Gram - Schmidt 正交化 的实现
		for (size_t k = 0; k < column; k++)
		{
			//获取结果矩阵当前列
			result_col = Column({ k });

			//不是正交基才进行处理
			if (k >= _column_start_)
			{
				//计算该列的范数
				norm_v = result_col.FrobeniusNorm();
				if (_R_) (*_R_)(k, k) = norm_v;

				//范数为0，说明线性相关，跳出循环
				if (norm_v == _NSelf::_Zero_) break;

				//将当前列标准化
				result_col *= _NSelf::_Unit_ / norm_v;
			}

			//令后续列减去当前列分量
			//从非正交基部分开始
			for (size_t j = _column_start_ > (k + 1) ? _column_start_ : (k + 1); j < column; j++)
			{
				back_col = Column({ j });
				norm_v = result_col % back_col;
				if (_R_) (*_R_)(k, j) = norm_v;
				back_col -= result_col * norm_v;
			}
		}

		return *this;
	}

	//获取 Householder 变换向量
	//需要指明以哪个位置作为基准位置（生成能将该元素下面的元素全部消去的向量）
	EasYMatrix_Head(EMSelf _NSelf) 
		HouseholderVector(size_t _row_, size_t _column_, bool erase_column, bool erase_back)
	{
		_DebugError_(_row_ >= row, "HouseholderVector", "The row is out of range!");
		_DebugError_(_column_ >= column, "HouseholderVector", "The column is out of range!");

		//获取部分列
		_NSelf part_col = erase_column ? Column({ _column_ }) : Row({_row_});
		if (erase_column)
		{
			if (_row_ > 0 && erase_back)
				part_col.SubMatrix(_row_, 1) = _NSelf::_Zero_;
			else if (_row_ + 1 < row && !erase_back)
				part_col.SubMatrix(_row_ + 1, row, 0, 1) = _NSelf::_Zero_;
		}
		else
		{
			if(_column_ > 0 && erase_back)
				part_col.SubMatrix(1, _column_) = _NSelf::_Zero_;
			else if (_column_ + 1 < column && !erase_back)
				part_col.SubMatrix(0, 1, _column_ + 1, column) = _NSelf::_Zero_;
		}

		//获取部分列的范数
		auto norm_v = erase_column ?
			part_col.SubMatrix(erase_back ? _row_ : 0, erase_back ? row : _row_ + 1, 0, 1).FrobeniusNorm()
			: part_col.SubMatrix(0, 1, erase_back ? _column_ : 0, erase_back ? column : _column_ + 1).FrobeniusNorm();

		//确定 alpha 方向
		if(part_col[erase_column ? _row_ : _column_] != _NSelf::_Zero_)
			part_col[erase_column ? _row_ : _column_] +=
				norm_v * (part_col[erase_column ? _row_ : _column_]
				/ abs(part_col[erase_column ? _row_ : _column_]));
		
		//向量规范化
		part_col.Normalization();

		return part_col;
	}

	//用 Householder 向量 v 生成矩阵 H 左乘于矩阵
	EasYMatrix_Head(EMSelf _Self&)
		HouseholderLeft(const _NSelf& _v_, _Ip _v_range_, _Ip _m_range_, bool erase_column)
	{
		_DebugError_(erase_column && _v_.row != row, "HouseholderLeft", "The row of vector must be same with matrix!");
		_DebugError_(!erase_column && _v_.column != column, "HouseholderLeft", "The column of vector must be same with matrix!");

		if (_v_range_.second == -1)
			_v_range_.second = erase_column ? row : column;
		if (_m_range_.second == -1)
			_m_range_.second = erase_column ? column : row;

		_DebugError_(_v_range_.first > _v_range_.second || _v_range_.first < 0 || _v_range_.second >(erase_column ? row : column), "HouseholderLeft", "Illegal vector range!");
		_DebugError_(_m_range_.first > _m_range_.second || _m_range_.first < 0 || _m_range_.second >(erase_column ? column : row), "HouseholderLeft", "Illegal matrix range!");

		//获取向量 v 的范数平方
		_Ty norm_v = _NSelf::_Zero_;
		for (size_t i = _v_range_.first; i < _v_range_.second; i++)
			norm_v += norm(_v_[i]);
		
		//线性相关，跳出
		if (norm_v == _NSelf::_Zero_)
			return *this;
		
		//对剩余子矩阵部分进行变换
		_RSelf alpha;
		_Ty temp_v;
		for (size_t j = _m_range_.first; j < _m_range_.second; j++)
		{
			alpha = erase_column ? Column({ j }) : Row({ j });
			temp_v = _v_ % alpha;
			alpha -= ((temp_v + temp_v) / norm_v) *  _v_ ;
		}

		return *this;
	}

	//用 Householder 向量 v 生成矩阵 H 右乘于矩阵
	EasYMatrix_Head(EMSelf _Self&)
		HouseholderRight(const _NSelf& _v_, _Ip _v_range_, _Ip _m_range_, bool erase_column)
	{
		_DebugError_(erase_column && _v_.row != column, "HouseholderRight", "The row of vector must be same with the column of matrix!");
		_DebugError_(!erase_column && _v_.column != row, "HouseholderRight", "The column of vector must be same with the row of matrix!");

		if (_v_range_.second == -1)
			_v_range_.second = erase_column ? column : row;
		if (_m_range_.second == -1)
			_m_range_.second = erase_column ? row : column; 

		_DebugError_(_v_range_.first > _v_range_.second || _v_range_.first < 0 || _v_range_.second >(erase_column ? column : row), "HouseholderRight", "Illegal vector range!");
		_DebugError_(_m_range_.first > _m_range_.second || _m_range_.first < 0 || _m_range_.second >(erase_column ? row : column), "HouseholderRight", "Illegal matrix range!");

		//获取向量 v 的范数平方
		_Ty norm_v = _NSelf::_Zero_;
		for (size_t i = _v_range_.first; i < _v_range_.second; i++)
			norm_v += norm(_v_[i]);

		//线性相关，跳出
		if (norm_v == _NSelf::_Zero_)
			return *this;

		//对剩余子矩阵部分进行变换
		_RSelf beta;
		_Ty temp_v;
		for (size_t j = _m_range_.first; j < _m_range_.second; j++)
		{
			beta = erase_column ? Row({ j }) : Column({ j });
			temp_v = (erase_column ? (beta * _v_) : (_v_ * beta))[0];
			beta -= ((temp_v + temp_v) / norm_v) * _v_.ConjugateTranspose();
		}

		return *this;
	}

	//Householder变换
	EasYMatrix_Head(EMSelf _Self&)
		HouseholderTransformation(size_t _start_row_)
	{
		_DebugError_(_start_row_ >= row, "HouseholderTransformation", "The row is out of range!");

		_NSelf v;
		size_t max_rank = (row - _start_row_) < column ? (row - _start_row_) : column;

		for (size_t k = 0; k < max_rank; k++)
		{
			//获取向量 v
			v = HouseholderVector(k + _start_row_, k);

			//对剩余子矩阵部分进行变换
			HouseholderLeft(v, k + _start_row_, k);
		}

		return *this;
	}

	//获取Givens变换矩阵
	EasYMatrix_Head(EMSelf _NSelf)
		GivensMatrix(size_t _column_, size_t _row_use_, size_t _row_erase_)
	{
		_DebugError_(_column_ >= column, "GivensMatrix", "The column is out of range!");
		_DebugError_(_row_use_ >= row, "GivensMatrix", "The row is out of range!");
		_DebugError_(_row_erase_ >= row, "GivensMatrix", "The row is out of range!");

		//计算 cos 和 sin 值
		_Ty sin_v, cos_v;
		//分情况，防止下溢和上溢
		if ((*this)(_row_erase_, _column_) == _NSelf::_Zero_)
		{
			sin_v = _NSelf::_Zero_;
			cos_v = _NSelf::_Unit_;
		}
		else if ((*this)(_row_use_, _column_) == _NSelf::_Zero_)
		{
			cos_v = _NSelf::_Zero_;
			sin_v = _NSelf::_Unit_;
		}
		else if (abs((*this)(_row_erase_, _column_)) > abs((*this)(_row_use_, _column_)))
		{
			_Ty q_v = (*this)(_row_use_, _column_) / (*this)(_row_erase_, _column_);
			_Ty norm_v = sqrt(_NSelf::_Unit_ + norm(q_v));
			sin_v = _NSelf::_Unit_ / norm_v;
			cos_v = q_v * sin_v;
		}
		else
		{
			_Ty q_v = (*this)(_row_erase_, _column_) / (*this)(_row_use_, _column_);
			_Ty norm_v = sqrt(_NSelf::_Unit_ + norm(q_v));
			cos_v = _NSelf::_Unit_ / norm_v;
			sin_v = q_v * cos_v;
		}

		//生成 Givens 矩阵
		_NSelf result(2, 2);
		if constexpr (IsComplex_<_Ty>::value)
		{
			result(0, 0) = conj(cos_v);
			result(0, 1) = conj(sin_v);
		}
		else
		{
			result(0, 0) = cos_v;
			result(0, 1) = sin_v;
		}
		result(1, 0) = -sin_v;
		result(1, 1) = cos_v;

		//复矩阵还要正交化
		if constexpr (IsComplex_<_Ty>::value)
			result *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return result;
	}

	//获取双边Givens变换矩阵
	EasYMatrix_Head(EMSelf _NSelf)
		BilateralGivensMatrix(size_t row1, size_t row2, size_t column1, size_t column2)
	{
		_DebugError_(row1 >= row || row2 >= row, "GivensMatrix", "The row is out of range!");
		_DebugError_(column1 >= column || column2 >= column, "GivensMatrix", "The column is out of range!");
		
		//计算 cos 和 sin 值
		_Ty tau = (*this)(row1, column1) - (*this)(row2, column2);
		_Ty t;
		if (tau == _NSelf::_Zero_)
		{
			t = sqrt((*this)(row2, column1) / (*this)(row1, column2));
		}
		else
		{
			t = ((*this)(row2, column1) + (*this)(row2, column1)) * tau 
				/ (abs(tau) * (abs(tau) + sqrt(tau * tau + _Ty(4) * (*this)(row2, column1) * (*this)(row1, column2))));
		}
		_Ty cos_v = _NSelf::_Unit_ / sqrt(_NSelf::_Unit_ + t * t), sin_v = t * cos_v;

		//生成双边 Givens 矩阵
		_NSelf result(2, 2);
		if constexpr (IsComplex_<_Ty>::value)
		{
			result(0, 0) = conj(cos_v);
			result(0, 1) = conj(sin_v);
		}
		else
		{
			result(0, 0) = cos_v;
			result(0, 1) = sin_v;
		}
		result(1, 0) = -sin_v;
		result(1, 1) = cos_v;

		//复矩阵还要正交化
		if constexpr (IsComplex_<_Ty>::value)
			result *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return result;
	}

	//左乘Givens变换矩阵
	EasYMatrix_Head(EMSelf _Self&) 
		GivensLeft(const _NSelf& _givens_matrix_, size_t _row1_, size_t _row2_)
	{
		_DebugError_(_givens_matrix_.row != 2 || _givens_matrix_.column != 2, "GivensLeft", "Givens matrix must be 2 x 2!");
		_DebugError_(_row1_ >= row || _row2_ >= row, "GivensLeft", "The row is out of range!");

		//获取要用到的两行
		_RSelf my_use, my_erase;
		_NSelf vec_use, vec_erase;
		my_use = this->Row({ _row1_ });
		my_erase = this->Row({ _row2_ });
		vec_use = my_use;
		vec_erase = my_erase;

		//计算结果
		my_use.Assgin(_givens_matrix_(0, 0) * vec_use + _givens_matrix_(0, 1) * vec_erase);
		my_erase.Assgin(_givens_matrix_(1, 0) * vec_use + _givens_matrix_(1, 1) * vec_erase);

		return *this;
	}

	//右乘Givens变换矩阵
	EasYMatrix_Head(EMSelf _Self&) 
		GivensRight(const _NSelf& _givens_matrix_, size_t _column1_, size_t _column2_)
	{
		_DebugError_(_givens_matrix_.row != 2 || _givens_matrix_.column != 2, "GivensRight", "Givens matrix must be 2 x 2!");
		_DebugError_(_column1_ >= column || _column2_ >= column, "GivensRight", "The column is out of range!");

		//获取要用到的两列
		_RSelf my_use, my_erase;
		_NSelf vec_use, vec_erase;
		my_use = this->Column({ _column1_ });
		my_erase = this->Column({ _column2_ });
		vec_use = my_use;
		vec_erase = my_erase;

		//计算结果
		my_use.Assgin(_givens_matrix_(0, 0) * vec_use + _givens_matrix_(1, 0) * vec_erase);
		my_erase.Assgin(_givens_matrix_(0, 1) * vec_use + _givens_matrix_(1, 1) * vec_erase);

		return *this;
	}

	//单次Givens变换
	EasYMatrix_Head(EMSelf _Self&)
		Givens(size_t _column_, size_t _row_use_, size_t _row_erase_)
	{
		_DebugError_(_column_ >= column, "Givens", "The column is out of range!");
		_DebugError_(_row_use_ >= row, "Givens", "The row is out of range!");
		_DebugError_(_row_erase_ >= row, "Givens", "The row is out of range!");

		//获取 Givens 矩阵
		auto gmat = GivensMatrix(_column_, _row_use_, _row_erase_);

		//计算结果
		GivensLeft(gmat, _row_use_, _row_erase_);

		return *this;
	}

	//Givens变换
	EasYMatrix_Head(EMSelf _Self&)
		GivensTransformation(size_t _start_row_)
	{
		_DebugError_(_start_row_ >= row, "GivensTransformation", "The row is out of range!");

		size_t max_rank = (row - _start_row_) < column ? (row - _start_row_) : column;

		for (size_t k = 0; k < max_rank; k++)
			for (size_t j = k + _start_row_ + 1; j < row; j++)
				Givens(k, k + _start_row_, j);

		return *this;
	}

	//让矩阵进行 QR 分解
	EasYMatrix_Head(void)
		QRDecomposition(_NSelf& _Q_, _NSelf& _R_, bool full) const
	{
		if (full)
		{
			//原理
			//求 QR = A
			//构造 B = [QR I]
			//对 B 进行 Householder 变换
			//最终得到 B = [R Q^(-1)]
			//再对 Q^(-1) 转置便得到 Q

			//第一步 - 构造 B
			_Q_.SetIdentity(this->Rows());
			_R_ = *this;
			_RSelf _B_ = _R_.Splicing(_Q_);

			//第二步 - Householder 变换
			_B_.HouseholderTransformation();

			//第三步 - 将 Q 转置
			_Q_ = _Q_.ConjugateTranspose();
		}
		else
		{
			//不完整 QR分解，仅使用施密特正交化即可
			_Q_ = *this;
			_Q_.GramSchmidtOrthogonalization(&_R_);
		}
	}

	//对矩阵作满秩分解
	EasYMatrix_Head(void)
		FullRankDecomposition(_NSelf& _F_, _NSelf& _G_) const
	{
		//先把矩阵通过高斯消元化为阶梯矩阵
		_NSelf temp_matrix = *this;
		temp_matrix.GaussianElimination();

		//用于记录线性无关的列向量
		Matrix<size_t> use_column(column, 1);
		size_t use_idx = 0;

		//通过初等行变换尽量化成左边近似单位阵的模样
		size_t _row = 0;
		size_t __last = 0;
		for (; _row < temp_matrix.Rows(); _row++)
		{
			bool _flag = true;
			for (size_t _column = __last; _column < temp_matrix.Columns(); _column++)
			{
				if (temp_matrix(_row, _column) != _NSelf::_Zero_)
				{
					use_column[use_idx++] = _column;
					_flag = false;
					temp_matrix.RowMultiply(_row, _NSelf::_Unit_ / temp_matrix(_row, _column));
					for (size_t __row = 0; __row < _row; __row++)
						if (temp_matrix(__row, _column) != _NSelf::_Zero_)
							temp_matrix.RowAdd(__row, _row, -temp_matrix(__row, _column));
					__last = _column + 1;
					break;
				}
			}
			if (_flag)
				break;
		}

		//观察得到F、G矩阵
		if (_row > 0)
		{
			_F_ = Column(use_column);
			_G_ = temp_matrix.SubMatrix(_row, column, true);
		}
	}

	//扩充基 - 对列向量
	EasYMatrix_Head(EMSelf _Self&)
		ExtendBase(size_t _rank_)
	{
		_DebugError_(row < _rank_ || column < _rank_, "ExtendBase", "The rank is out of range!");

		//获取矩阵某一行的首元素所在位置
		auto get_first_of_row = [](const _NSelf& mat, size_t _row_) -> size_t
		{
			for (size_t i = 0; i < mat.Columns(); i++)
				if (mat(_row_, i) != _NSelf::_Zero_)
					return i;
			return mat.Columns();
		};

		_NSelf temp_mat;
		Matrix<size_t> record_vec;

		//第一步 - 转置并化为阶梯型矩阵
		temp_mat = this->Transpose();
		temp_mat.GaussianElimination();

		//第二步 - 找出每一行，第一个非零元所在列
		record_vec.Reshape(_rank_, 1);
		for (size_t i = 0; i < _rank_; i++)
			record_vec[i] = get_first_of_row(temp_mat, i);
		
		//第三步 - 扩充为完备基
		this->Reshape(row, row);
		size_t j = _rank_;
		size_t idx = 0;
		for (size_t i = 0; i < row && j < column; i++)
		{
			if (idx < _rank_ && i == record_vec[idx])
			{
				idx++;
			}
			else
			{
				this->Column({j}) = _NSelf::_Zero_;
				(*this)(i, j) = _NSelf::_Unit_;
				j++;
			}
		}

		return *this;
	}

	//对矩阵作舒尔分解
	EasYMatrix_Head(void)
		SchurDecomposition(_NSelf& _T_, _NSelf* _U_, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "SchurDecomposition", "The matrix must be square!");

		_T_ = *this;
		if(_U_)_U_->SetIdentity(row);

		//进行缩放
		_Ty scaling_coe;
		_T_.Normalization(&scaling_coe);

		//矩阵上 Hessenberg 化
		_NSelf v;
		for (size_t k = 1; k < row; k++)
		{
			//获取向量 v
			v = _T_.HouseholderVector(k, k - 1);

			//左乘并右乘 Householder 矩阵
			_T_.HouseholderLeft(v, k, k - 1).HouseholderRight(v, k, 0);
			if(_U_)_U_->HouseholderRight(v, k, 0);
		}

		//矩阵操作边界
		size_t i_begin = 0, i_end = row - 1;

		//清理下副对角线的下侧
		//此函数非常重要，对于大型矩阵，该函数能有效防止误差在下三角的累积迁移到上三角
		auto clear_low_diag = [&]()
		{
			if (row < 2) return;
			size_t row_begin = i_begin >= 2 ? i_begin : 2;
			size_t column_begin = i_begin >= 2 ? i_begin - 2 : 0;
			size_t times = std::min(std::min(i_end - i_begin + 3, row - row_begin), column - column_begin);

			for (size_t i = 0; i < times; i++)
				_T_(row_begin + i, column_begin + i) = _NSelf::_Zero_;
		};

		/**
		* 误差分析
		*/
		auto Error_Analyze = [&]()
		{
		ERROR_AGAIN:

			//处理完毕，取消分析
			if (i_end == 0)
				return;

			//分析处理的区域有多大
			size_t res = i_end;
			while (res)
			{
				_Ty error_p = abs(_T_(res - 1, res - 1)) + abs(_T_(res, res));

				if (abs(_T_(res, res - 1)) < max_error)
					break;
				res--;
			}
			i_begin = res;

			//如果是 1x1 或 2x2
			//直接排除，再次分析
			if (i_begin == i_end)
			{
				i_end--;
				goto ERROR_AGAIN;
			}
			else if (i_begin + 1 == i_end)
			{
				//需要判断该 2x2 区域是否是实特征值的
				//复数矩阵不需要进行这步判断
				_Ty trace_v = _T_(i_begin, i_begin) + _T_(i_end, i_end),
					det_v = _T_(i_begin, i_begin) * _T_(i_end, i_end) - _T_(i_begin, i_end) * _T_(i_end, i_begin),
					delta_v = trace_v * trace_v - _Ty(4) * det_v;

				//加 real 过编译
				if (IsComplex_<_Ty>::value || real(delta_v) >= real(_NSelf::_Zero_))
				{
					auto givens_mat = _T_.BilateralGivensMatrix(i_begin, i_end, i_begin, i_end);
					_T_.GivensLeft(givens_mat, i_begin, i_end);
					_T_.GivensRight(givens_mat.ConjugateTranspose(), i_begin, i_end);
					if(_U_)_U_->GivensRight(givens_mat.ConjugateTranspose(), i_begin, i_end);
					clear_low_diag();
				}

				if (i_end == 1) i_end = 0;
				else i_end -= 2;
				goto ERROR_AGAIN;
			}
		};
		
		//QR 迭代
		while (i_end > 0)
		{
			//位移量
			_Ty dist_v = _T_(i_end, i_end);
			for (size_t i = i_begin; i <= i_end; i++)
				_T_(i, i) -= dist_v;

			//Givens旋转 实现 QR迭代
			for (size_t i = i_begin; i < i_end; i++)
			{
				_NSelf givens_mat = _T_.GivensMatrix(i, i, i + 1);
				_T_.GivensLeft(givens_mat, i, i + 1);
				_T_.GivensRight(givens_mat.ConjugateTranspose(), i, i + 1);
				if(_U_)_U_->GivensRight(givens_mat.ConjugateTranspose(), i, i + 1);
			}

			//清理下副对角线的下侧
			clear_low_diag();

			//补回位移量
			for (size_t i = i_begin; i <= i_end; i++)
				_T_(i, i) += dist_v;
			
			//分析误差 - 选择处理区域
			Error_Analyze();
		}

		//清除下三角部分
		for (size_t i = 2; i < row; i++)
			for (size_t j = 0; j < i - 1; j++)
				_T_(i, j) = _NSelf::_Zero_;

		//清理下副对角线
		for (size_t i = 1; i < row; i++)
			if(abs(_T_(i, i - 1)) < max_error)
				_T_(i, i - 1) = _NSelf::_Zero_;

		//放大回去
		_T_ *= _NSelf::_Unit_ / scaling_coe;
	}

	//对矩阵作奇异值分解
	EasYMatrix_Head(void)
		SVDDecomposition(_NSelf& _S_, _NSelf* _V_, _NSelf* _U_, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		//列大于行的情况
		if (this->column > this->row)
		{
			auto tmp_mat = this->ConjugateTranspose();
			tmp_mat.SVDDecomposition(_S_, _U_, _V_, max_error);
			_S_ = _S_.ConjugateTranspose();
			return;
		}

		//是否进行二次分解
		bool is_snd_decom = _V_ != nullptr && _U_ != nullptr;

		//第一次用于分解的矩阵
		_NSelf* fst_dec_mat = _V_ ? _V_ : _U_;

		//1.进行第一次特征分解 - 必然得到 S^2 矩阵
		_NSelf evd_mat = (fst_dec_mat == _U_) ? (*this * this->ConjugateTranspose()) : (this->ConjugateTranspose() * *this);
		//清除掉矩阵的零元
		IndexMatrix dc_vec;
		evd_mat.ZeroReduction(max_error, &dc_vec);
		//雅可比方法求特征值
		evd_mat = evd_mat.BilateralJacobiMethod(fst_dec_mat, max_error);

		//2.对 S^2 的对角元素开方得到 S
		//矩阵的最大秩
		size_t max_rank = row > column ? column : row;
		if (dc_vec.Size())
		{
			//如果有清除行列，要更新 max_rank
			if (max_rank > evd_mat.Rows())
				max_rank = evd_mat.Rows();

			//并且要扩充 V
			_V_->Reshape(column, column, _NSelf::_Zero_);
			for (size_t i = 0; i < dc_vec.Size(); i++)
				(*_V_)(column - 1 - i, column - 1 - i) = _NSelf::_Unit_;
		}

		_S_.Reshape(this->row, this->column, _NSelf::_Zero_);
		for (size_t i = 0; i < max_rank; i++)
			_S_(i, i) = sqrt(evd_mat(i, i));
		
		//2.5.如果有清除行列，需要调整 V 的顺序
		for(size_t i = 0; i < dc_vec.Size(); i++)
			for (size_t j = dc_vec[i]; j < evd_mat.Rows() + i; j++)
				_V_->RowExchange(j, j + 1).ColumnExchange(j, j + 1);

		//3.进行第二次分解 - 如果需要的话
		if (is_snd_decom)
		{
			//由 AV = US
			//即 (AV){nxn} = [s1 * u1 ,s2 * u2 ... ,sn * un] 可解得 u1,u2 ... un
			//然后扩充 U，再进行正交化即可

			*_U_ = *this * *_V_;
			size_t u_rank = 0;
			for (; u_rank < max_rank; u_rank++)
			{
				if (_S_(u_rank, u_rank) != _NSelf::_Zero_)
				{
					_U_->ColumnMultiply(u_rank, _NSelf::_Unit_ / _S_(u_rank, u_rank));
				}
				else
				{
					break;
				}
			}
			
			//进行扩充或收缩
			if (row > u_rank)
			{
				_U_->ExtendBase(u_rank);
				_U_->GramSchmidtOrthogonalization(nullptr, u_rank);
			}
			else if (row < u_rank)
			{
				_U_->Reshape(row, row);
			}
		}
	}

	//求伪逆矩阵
	EasYMatrix_Head(EMSelf _NSelf) 
		PseudoInverse() const
	{
		//进行 SVD 分解
		_NSelf U, S, V;
		this->SVDDecomposition(S, &V, &U);

		//将 S 的对角线元素取倒数
		size_t max_rank = std::min(S.Rows(), S.Columns());
		for (size_t i = 0; i < max_rank; i++)
		{
			if (S(i, i) != _NSelf::_Zero_)
				S(i, i) = _NSelf::_Unit_ / S(i, i);
			else
				break;
		}

		//求出广义逆
		return V * S.ConjugateTranspose() * U.ConjugateTranspose();
	}

	//上 Hessenberg 化
	EasYMatrix_Head(EMSelf _Self&)
		UpperHessenbergTransformation()
	{
		_DebugError_(row != column, "UpperHessenbergTransformation", "The matrix must be square!");

		_NSelf v;
		for (size_t k = 1; k < row; k++)
		{
			//获取向量 v
			v = HouseholderVector(k, k - 1);

			//左乘并右乘 Householder 矩阵
			HouseholderLeft(v, k, k - 1).HouseholderRight(v, k, 0);
		}

		return *this;
	}

	//双对角化
	EasYMatrix_Head(EMSelf _Self&)
		Bidiagonalization()
	{
		_NSelf v;
		size_t max_rank = row > column ? column : row;

		for (size_t i = 0; i < max_rank - 1; i++)
		{
			v = HouseholderVector(i, i);
			HouseholderLeft(v, i, i);

			if (i != (max_rank - 1))
			{
				v = HouseholderVector(i, i + 1, false);
				HouseholderLeft(v, i + 1, i, false);
			}
		}

		return *this;
	}

	//三对角化
	EasYMatrix_Head(EMSelf _Self&)
		Tridiagonalization()
	{
		_NSelf v;
		size_t max_rank = row > column ? column : row;

		for (size_t i = 0; i < max_rank - 2; i++)
		{
			v = HouseholderVector(i + 1, i);
			HouseholderLeft(v, i + 1, 0);

			v = HouseholderVector(i, i + 1, false);
			HouseholderLeft(v, i + 1, i, false);
		}

		return *this;
	}

	//自动清除全为 0 的行和列
	EasYMatrix_Head(EMSelf _Self&)
		ZeroReduction(const decltype(norm(std::declval<_Ty>()))& thresh_val, Matrix<size_t>* rows_clear, Matrix<size_t>* column_clear)
	{
		if (Empty())return *this;

		Matrix<size_t> index_vec;
		size_t real_size;

		//消去行
		real_size = 0;
		index_vec.Reshape(row, 1);
		for (size_t i = 0; i < row; i++)
		{
			bool all_zero = true;
			for (size_t j = 0; j < column; j++)
			{
				if (abs((*this)(i, j)) > thresh_val)
				{
					all_zero = false;
					break;
				}
			}
			if (all_zero)
				index_vec[real_size++] = i;
		}
		index_vec.Reshape(real_size, 1);
		if (real_size)
			*this = this->RowCrossOut(index_vec);
		if (rows_clear)
			rows_clear->Swap(index_vec);

		//消去列
		real_size = 0;
		index_vec.Reshape(column, 1);
		for (size_t j = 0; j < column; j++)
		{
			bool all_zero = true;
			for (size_t i = 0; i < row; i++)
			{
				if (abs((*this)(i, j)) > thresh_val)
				{
					all_zero = false;
					break;
				}
			}
			if (all_zero)
				index_vec[real_size++] = j;
		}
		index_vec.Reshape(real_size, 1);
		if (real_size)
			*this = this->ColumnCrossOut(index_vec);
		if (column_clear)
			column_clear->Swap(index_vec);

		return *this;
	}

	//矩阵标准化
	//可获取标准化均值和标准化方法
	EasYMatrix_Head(EMSelf _Self&)
		Standardization(_Ty* _mean_, _Ty* _standard_deviation_)
	{
		if (Empty())return *this;

		_Ty m = _NSelf::_Zero_, v = _NSelf::_Zero_;

		//归一化
		//防止上溢
		_Ty coe;
		Normalization(&coe);

		//遍历计算
		auto read_ptr = form;
		size_t _size_ = row * column;
		_Ty _div = _NSelf::_Unit_ / _Ty(_size_);
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			m += *read_ptr,
			v += *read_ptr * *read_ptr;
		m *= _div;
		v = _div * sqrt(v);

		//矩阵标准化
		*this -= m;
		*this *= _NSelf::_Unit_ / v;

		//参数调整
		m /= coe;
		v /= coe;

		//返回 均值 和 方差
		if (_mean_) *_mean_ = m;
		if (_standard_deviation_) *_standard_deviation_ = v;

		return *this;
	}

	//矩阵归一化
	//可获取缩放系数
	EasYMatrix_Head(EMSelf _Self&)
		Normalization(_Ty* _Coe)
	{
		if (Empty())return *this;

		_Ty max_v = _NSelf::_Zero_;

		//找出模最大值
		auto read_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			if (abs(*read_ptr) > abs(max_v))
				max_v = *read_ptr;

		//进行缩放
		max_v = _NSelf::_Unit_ / max_v;
		*this *= max_v;

		if (_Coe) *_Coe = max_v;
		return *this;
	}

	//获取缩放系数（缩放到指数部分对称）
	EasYMatrix_Head(auto)
		ScalingCoefficient() const
	{
		using T = decltype(norm(std::declval<_Ty>()));
		T max_norm = T(1), min_norm = T(1), now_norm;

		//寻找最大模最大和模最小的值
		auto read_ptr = form;
		size_t _size_ = row * column;
		//避免未赋值
		bool no_max = true, no_min = true;
		for (size_t i = 0; i < _size_; i++, read_ptr++)
		{
			if (PtCast(*read_ptr) != _NSelf::_Zero_)
			{
				now_norm = abs(PtCast(*read_ptr));
				if (no_max || now_norm > max_norm)
				{
					max_norm = now_norm;
					no_max = false;
				}
				if (no_min || now_norm < min_norm)
				{
					min_norm = now_norm;
					no_min = false;
				}
			}
		}

		return T(1) / (sqrt(min_norm) * sqrt(max_norm));
	}
}

#pragma pop_macro("EMSelf")
#pragma pop_macro("new")

#endif