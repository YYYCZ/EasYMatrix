/*
* EasYMatrix ���� By YYYCZ
* EasYMatrix ��Ϊ�򵥵ľ���ּ�������������Ĵ��룬��򵥵ķ�������򵥵�ʹ�ã�ʵ�־�����ص���๦��
* EasYMatrix �ṩ��һ�־���ģ���� Matrix ��ֻҪ�ṩ������Ԫ�ص����ͼ��ɣ� �� һ�־��������� RMatrix ������ʵ�ֶԾ���Ĳ��ֲ�����
* 
* ��Ҫע�⣬�þ������������ռ� EasYMatrix �µ�
* 
* Matrix �е� type ��Ҫ�ṩ�ĺ����������Ƽ�ʹ��C++���õ�complex���з�װ����������в���Ԥ֪�Ĵ��󣩣�
* 1.sqrt - ����
* 2.conj - ȡ����
* 3.abs - ȡ����ֵ�������Ļ�����ȡģֵ��
* 4.norm - ��ģ��ƽ�����Ǹ�������ֱ��ƽ����
* 5.real - ȡ������ʵ��
* 6.imag - ȡ�������鲿
*/

/*
* ������־ | Start | By YYYCZ
* 1.ʵ���˾���Ļ�������
* 2.ʵ���˾������������
* 3.ȷ����Debug�µı������
* 
* 
* 
* ������־ | 2021 - 9 | By YYYCZ
* 1.�������ĳ������б任����
* 2.�����˾���������ʽ��
* 
* 
* 
* ������־ | 2021 - 10 - 07 | By YYYCZ
* 1.�����˸�˹��Ԫ�͸�˹������Ԫ�㷨
* 2.������ʩ�����������㷨
* 3.���������ȷֽ��㷨
* 4.������ 1-������ ������� Frobenius �����ļ���
* 5.�����˶Խǻ������ļ���
* 6.�����˾����棬����ʽ�ļ���
* 7.������ LU �ֽ��㷨
* 
* 
* 
* ������־ | 2021 - 10 - 08 | By YYYCZ
* 1.���������þ����� RMatrix ��ʵ�������� Matrix ��ʵ�ֵģ�
* 2.����ȡ������ĺ������� Row��SubMatrix �ȣ��ķ���ֵ��Ϊ RMatrix
* 3.���� Copy ���������Խ� RMatrix תΪ������ Matrix
* 4.���� Assign ������RMatrix ���ô˺��������޸����õ�ֵ����ͨ��ֵ���޸����ã�
* 5.RMatrix ����ͨ����ʼ���б������޸�ֵ
* ע�⣺����� RMatrix ����ĳЩ��ֵ�ຯ������ SetOne��SetRandom �ȣ���������δ֪����
* 
* 
* 
* ������־ | 2021 - 10 - 09 | By YYYCZ
* 1.�޸���������ĸ�ֵ�ຯ�����⣨������������Ե��ø�ֵ�ຯ���ˣ�
* 2.�����˶������������
* 3.�޸������������� Resize �� Splicing ����
* 4.�����������Ż��˲����㷨
* 5.ʵ�־����ıȽ������ɲ�������BoolMatrix��
* 6.ʵ���˾�������
* 7.�������Զ�����㡢�Ƚϡ���������
* 8.���� Reshape ������ԭԪ�ذ�˳�����·���
* 9.���� Take ����������������еķ���Ԫ������һ�������Ԫ�ذ�˳���滻
* 10.���� Mask �����������þ����������
* 11.������ Householder �任 �� Givens �任
* 
* 
* 
* ������־ | 2021 - 10 - 10 | By YYYCZ
* 1.����˶Ը�����֧�̶ֳ�
* 2.������ 2-���� �ļ���
* 3.������ �ݷ� �� �����̵���
* 4.������ ���� �� ����ת�� ����
* 5.�Ż����ֺ���
* 6.�޸�����ԭ�ȸ�������������bug
* 7.��������ֵ���� Threshold
* 8.�Ľ��� Row��Column �Ⱥ���
* 9.�����ʹ�� C++ �⺯��
* 10.����������
* 
* 
* 
* ������־ | 2021 - 10 - 11 | By YYYCZ
* 1.���Ӿ���� ������ˣ�Mutiply�������������\�����������ࣨSurplus��
* 2.������ FlipLeftAndRight��FlipUpAndDown��Rotate90 �ķ��������ҷ�ת�����·�ת����ʱ����ת�����90��[Ĭ��һ��]��
* 3.��ֵ���� Threshold ��һ��������Ϊ��ʼ���б�
* 4.�����Զ���ֵ���� AutoThreshold
* 5.������ QR�ֽ��㷨
* 6.����� AbsoluteTrace ���Լ��ļ���
* 7.������ QRIteration ����������������ֵ
* 8.���� UpperHessenbergTransformation ����
* 
* 
* 
* ������־ | 2021 - 10 - 12 | By YYYCZ
* 1.�� Householder�任 ��ֳɶ������ - ������������ˡ��ҳ�
* 2.�Ż��˲����㷨
* 3.�����±��������ȡ���־��� - [] ѡȡ���� - () ��������
* 4.���� QRIteration �㷨
* 5.���������Ǿ���ĳ˷��㷨
* 
* 
* 
* ������־ | 2021 - 10 - 13 | By YYYCZ
* 1.��һ��ϸ�� Householder �㷨
* 2.���� ˫�Խǻ� �� ���Խǻ� ����
* 3.���� Jacobi ����
* 4.���� SVD ����ֵ�ֽⷽ��
* 
* 
* 
* ������־ | 2021 - 10 - 14 | By YYYCZ
* 1.ʵ�����������
* 2.���� SVD ����ֵ�ֽ��㷨
* 3.������Ԫ��ά����
* 4.���� ��׼�� ����
* 5.���� ���� ����
* 6.�Ż��˲����㷨
* 7.������ α����� �ķ���
* 
* 
* 
* ������־ | 2021 - 10 - 17 | By YYYCZ
* 1.������루������ŵ�һ��������ʵ�֣�
* 2.�� Givens ��ת �� Jacobi ��ת���
* 3.���� ����ֽ� ����
* 4.���� QRIteration ������ȫ������ ����ֽ�
* 5.���� ���ǳ˷� ����
* 
* 
* 
* ������־ | 2021 - 10 - 18 | By YYYCZ
* 1.��������ָ���Գƻ��ı���ϵ������
* 2.�Ż��� Givens ��ת���������㷨
* 3.�Ż��� FrobeniusNorm �㷨
* 4.�Ż��� Householder ��ת���������㷨
* 5.�Ż��˱�׼���������Զ����ź�������Ϊ��һ������
* 6.�޸��������н��������þ����µ�bug
* 
* 
* 
* ������־ | 2021 - 10 - 22 | By YYYCZ
* 1.�޸� Eigvalues ����������Ĳ�������������BUG
* 
* 
* 
* ������־ | 2021 - 12 - 06 | By YYYCZ
* 1.�޸� SVD �ֽ⵱������������ʱ��bug
* 2.�Ż��� SetRandom ����
* 3.�޸��˾��󿽱���Resize �� Reshape ������վ����bug
* 
* 
* 
* ������־ | 2021 - 12 - 08 | By YYYCZ
* 1.�� QR �ֽ�������Ƿ������ֽ��ѡ��
* 2.ʩ��������������ͬʱ��ȡ R ����
* 3.�޸���ȡ���־����bug
* 
* 
* 
* ������־ | 2021 - 12 - 09 | By YYYCZ
* 1.���� Householder �任��ز���
* 2.���������� _Ip
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
	//�ͷű�׼�⺯��
	using std::conj;
	using std::abs;
	using std::norm;
	using std::real;
	using std::imag;

	//�ж�һ�������Ƿ�Ϊ reference_wrapper
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v = false;
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v<std::reference_wrapper<_Ty>> = true;
	template<class _Ty>
	_INLINE_VAR constexpr bool is_reference_wrapper_v<std::reference_wrapper<const _Ty>> = true;
	template <class _Ty>
	struct is_reference_wrapper : std::bool_constant<is_reference_wrapper_v<_Ty>> {};

	//�Ƴ� _Ty �� reference_wrapper
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
	
	//����������������飬��Ҫ��<_Ty>ָ������
	template<class _Ty>
	inline void PackIntoArray(_Ty* _array_) {}

	template<class _Ty, class ..._Valty>
	inline void PackIntoArray(_Ty* _array_, const _Ty& _value_, _Valty&&... _package_)
	{
		*_array_++ = _value_;
		PackIntoArray<_Ty>(_array_, _package_...);
	}

	//��ȡ���ֵ
	template<class _Ptr_, class _Meth_>
	_Ptr_ getMax(_Ptr_ _begin_, _Ptr_ _end_, _Meth_ _method_)
	{
		_Ptr_ max_ptr = _begin_;
		while (_begin_ != _end_)
			if (_method_(max_ptr) < _method_(_begin_++))
				max_ptr = _begin_;
		return max_ptr;
	}

	//�Ƿ��Ǹ����� - C++�Դ�
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

	//�Ƴ�������
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

	//EasYMatrix - ������
	template<class _Tt>
	class Matrix
	{
	public:
		//����������
		using _Ty = typename remove_reference_wrapper<_Tt>::type;
		//���󴢴����� - ģ����������
		using _Pt = _Tt;
		//��������
		using _Rt = std::reference_wrapper<_Ty>;
		//ԭʼ�������� - ������������ͬ
		using _Self = Matrix<_Pt>;
		//�����þ�������
		using _NSelf = Matrix<_Ty>;
		//���þ�������
		using _RSelf = Matrix<_Rt>;
		//������
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

		//��������
		using _Ct = std::complex<typename remove_complex<_Ty>::type>;
		//����������
		using _CSelf = Matrix<_Ct>;
		//�������þ�����
		using _CRSelf = Matrix<std::reference_wrapper<_Ct>>;

		//��֤��ͬ���ͼ�� Matrix �� protect �� private �еķ����ͱ��������໥����
		template<class _TT> friend class Matrix;

	public:
		static _Ty _Zero_;//��Ԫ
		static _Ty _Unit_;//��λԪ
		static _Ty _Default_;//Ĭ��Ԫ

#ifdef _IOSTREAM_
		//��������
		template<class _TT> friend std::istream& operator>> (std::istream& in, Matrix<_TT>& _matrix_);
		template<class _TT> friend std::enable_if_t<is_reference_wrapper_v<_TT>, std::istream&> 
			operator>>(std::istream& in, const Matrix<_TT>& _matrix_);
		//�������
		template<class _TT> friend std::ostream& operator<< (std::ostream& out, const Matrix<_TT>& _matrix_);
#endif

		//�� _Pt ����ת�� _Ty ����
		static constexpr _Ty& PtCast(_Pt& ptv);

		//����ǿת
		template<class _RV>
		std::enable_if_t<!IsComplex_<_Ty>::value, _RV> ComCast(const std::complex<_RV>& _com_) { return real(_com_); };
		template<class _RV>
		static constexpr _RV& ComCast(const _RV& _com_) { return const_cast<_RV&>(_com_); }

	protected:	/* ������һЩ���������ݺͷ��� */
		_Pt* form = nullptr;	//������ڴ��ַ
		size_t capacity = 0;	//����ռ���ڴ�ռ�Ĵ�С
		size_t row = 0;			//��������
		size_t column = 0;		//��������

		//Ϊ form �����ڴ�
		void _Allocate_(size_t _size_);

		//�ͷ� form ���ڴ�
		void _Deallocate_();

		//��һ���µ��ڴ�ռ䱣������ص����֣����¾ɾ��󶼰����Ĳ��֣��´����ȥ�����ص������� _value_ ���
		void _NewForm_(size_t _row_, size_t _column_, const _Ty& _value_, bool _to_set_value_ = true);

		//�Ѿ���ռ�õ��ڴ��ͷŵ�
		void _FreeForm_() noexcept;

		//�Ծ���������
		template<class _RV>
		void _CopyForm_(_RV* _array_, size_t _row_, size_t _column_);

		//debugģʽ�±���
		void _DebugError_(bool error_condition, const char* function_name, const char* error_msg) const;

	public:		/* ���졢�������ڴ���� */

		//�������Ѿ���ռ���ڴ��ͷŵ�
		~Matrix() noexcept;

		//��ʼ��һ���վ���
		Matrix() = default;

		//�ṩ��������Ԫ��ֱ�ӹ������
		Matrix(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_) noexcept;
		
		//�ṩ��������������һ������
		Matrix(size_t _row_, size_t _column_) noexcept;

		//�ṩ�����������ͳ�ʼֵ����һ������
		Matrix(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//�������죨�����ǲ�ͬ���͵ľ���
		Matrix(const _Self& _matrix_) noexcept;
		_Self& operator=(const _Self& _matrix_) noexcept;
		template<class _RV>
		Matrix(const Matrix<_RV>& _matrix_) noexcept;
		template<class _RV>
		_Self& operator=(const Matrix<_RV>& _matrix_) noexcept;
		template<class _RV>
		_Self& Assgin(const Matrix<_RV>& _matrix_) noexcept;

		//ֵ����
		_Self& operator=(const _Ty& _value_) noexcept;
		_Self& Assgin(const _Ty& _value_) noexcept;

		//ͨ����ʼ���б���
		_Self& operator=(std::initializer_list<std::initializer_list<_Ty>> _mutiple_value_);

		//����������ʼ������
		template<class _RV>
		Matrix(const _RV* _array_, size_t _row_, size_t _column_);

		//�ú�������ʼ������
		Matrix(std::function<_Pt(size_t, size_t)> _method_, size_t _row_, size_t _column_);

		//ʵ�־��������ת������ʽ���ã�
		template<class _RV>
		explicit operator Matrix<_RV>();

		//���󿽱�
		_NSelf Copy();

		//��������������ڴ棨���Ὣ�����е�Ԫ�ؽ�����
		template<class _RV>
		_Self& Swap(Matrix<_RV>& _matrix_);
		
		//�������þ����С
		_Self& Resize(size_t _row_, size_t _column_) noexcept;

		//�������þ����С������������ֵΪ _value_
		_Self& Resize(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//�������þ����С��ԭ��Ԫ�ذ�˳�����
		_Self& Reshape(size_t _row_, size_t _column_) noexcept;

		//�������þ����С��ԭ��Ԫ�ذ�˳����䣬����������ֵΪ _value_
		_Self& Reshape(size_t _row_, size_t _column_, const _Ty& _value_) noexcept;

		//���þ�������Ԫ�ص�ֵΪͬһ��ֵ _value_
		_Self& SetValue(const _Ty& _value_) noexcept;

		//���þ���Ϊ��λ����
		_Self& SetIdentity(size_t _dim_) noexcept;

		//�������е�ÿһ��Ԫ�������ֵ
		//��Ҫ�ṩ��������ɺ���
		template<class _Pred>
		_Self& SetRandom(_Pred pf) noexcept;

		//��վ��󣨲����ռ�õ��ڴ棩
		_Self& Clear() noexcept;

		//��ȡ�����Ԫ��ռ�õ��ڴ��С
		size_t Memory() const noexcept;

	public:		/* ����λ�á���С��� */

		//��ȡ��������
		size_t Rows() const noexcept;

		//��ȡ��������
		size_t Columns() const noexcept;

		//��ȡ����Ԫ�ظ���
		size_t Size() const noexcept;

		//�����Ƿ�Ϊ��
		bool Empty() const noexcept;

		//��ȡ�����ĳ��λ���ϵ�Ԫ��
		_Ty& operator()(size_t _row_, size_t _column_);
		const _Ty& operator()(size_t _row_, size_t _column_) const;
		_Ty& operator[](size_t _idx_);
		const _Ty& operator[](size_t _idx_) const;

		//��ȡ�������еľ���
		_RSelf operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_);
		_NSelf operator[](std::pair<std::initializer_list<size_t>, std::initializer_list<size_t>> _ip_) const;

		//��һ�������ȡ����
		//�� const ����������������
		//const ���ؿ���������
	protected:
		template<class _RV, class _Mt>
		Matrix<_Mt> _Index_(const Matrix<_RV>&_idx_matrix_) const;
	public:
		template<class _RV>
		_RSelf operator()(const Matrix<_RV>&_idx_matrix_);
		template<class _RV>
		_NSelf operator()(const Matrix<_RV>&_idx_matrix_, bool _PLACEHOLDER_ = true) const;

		//�������еķ���Ԫ�����滻�����Ԫ�ذ�˳���滻
		template<class _RV>
		auto Take(const Matrix<_RV>&_rpl_matrix_) const;

		//����һ������Ըþ����������
		template<class _RV>
		_Self& Mask(const Matrix<_RV>& _kernel_matrix_);

		//��ȡ�����һ�л����
		//֧����������������
	protected:
		template<class _RV>
		Matrix<_RV> Row(const size_t * _index_list_, size_t _size_) const;
	public:
		_RSelf Row(std::initializer_list<size_t> _multiple_index_);
		_NSelf Row(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf Row(const Matrix<size_t>& _index_matrix_);
		_NSelf Row(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//��ȡ�����һ�л����
		//֧����������������
	protected:
		template<class _RV>
		Matrix<_RV> Column(const size_t * _index_list_, size_t _size_) const;
	public:
		_RSelf Column(std::initializer_list<size_t> _multiple_index_);
		_NSelf Column(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf Column(const Matrix<size_t>& _index_matrix_);
		_NSelf Column(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//��ȥ����һ�л����
	protected:
		template<class _RV>
		Matrix<_RV> RowCrossOut(const size_t* _index_list_, size_t _size_) const;
	public:
		_RSelf RowCrossOut(std::initializer_list<size_t> _multiple_index_);
		_NSelf RowCrossOut(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf RowCrossOut(const Matrix<size_t>& _index_matrix_);
		_NSelf RowCrossOut(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//��ȥ�����һ�л����
	protected:
		template<class _RV>
		Matrix<_RV> ColumnCrossOut(const size_t* _index_list_, size_t _size_) const;
	public:
		_RSelf ColumnCrossOut(std::initializer_list<size_t> _multiple_index_);
		_NSelf ColumnCrossOut(std::initializer_list<size_t> _multiple_index_, bool _PLACEHOLDER_ = true) const;
		_RSelf ColumnCrossOut(const Matrix<size_t>& _index_matrix_);
		_NSelf ColumnCrossOut(const Matrix<size_t>& _index_matrix_, bool _PLACEHOLDER_ = true) const;

		//�����ν�ȡ���־���
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

		//ƴ����һ�����������ҡ���������ģʽ��
		//Ĭ������ƴ��
		//ע�⣺ƴ�Ӿ����������ƥ��
	protected:
		template<class _RV>
		Matrix<_RV> Splicing(const _Self& _matrix_, bool left_right = true) const;
	public:
		_RSelf Splicing(_Self & _matrix_, bool left_right = true);
		_NSelf Splicing(const _Self& _matrix_, bool left_right = true, bool _PLACEHOLDER_ = true) const;

	public:		/* �������ת���Գ� */

		//����ת��
		_NSelf Transpose() const;

		//����ת��
		_NSelf ConjugateTranspose() const;

		//���·�ת
		_NSelf FlipUpAndDown() const;

		//���ҷ�ת
		_NSelf FlipLeftAndRight() const;

		//��ʱ����ת n �� 90��
		_NSelf Rotate90(int _n_ = 1) const;

	public:		/* ����ıȽ�  */

		//�ȽϺ�������Ҫ�ṩ�ȽϷ���
		template<class _RV, class _BL>
		Matrix<bool> Compare(const Matrix<_RV>& _matrix_, std::function<_BL(const _Tt&, const _RV&)> _method_) const;
		template<class _RV, class _BL>
		Matrix<bool> Compare(const _RV& _value_, std::function<_BL(const _Tt&, const _RV&)> _method_) const;

		//����
		template<class _RV>
		Matrix<bool> operator==(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator==(const _RV& _value_) const;

		//������
		template<class _RV>
		Matrix<bool> operator!=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator!=(const _RV& _value_) const;

		//����
		template<class _RV>
		Matrix<bool> operator>(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator>(const _RV& _value_) const;

		//С��
		template<class _RV>
		Matrix<bool> operator<(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator<(const _RV& _value_) const;

		//���ڵ���
		template<class _RV>
		Matrix<bool> operator>=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator>=(const _RV& _value_) const;

		//С�ڵ���
		template<class _RV>
		Matrix<bool> operator<=(const Matrix<_RV>& _matrix_) const;
		template<class _RV>
		Matrix<bool> operator<=(const _RV& _value_) const;

	public:		/* ����������� */

		//������ÿһ��������һ������Ķ�Ӧ���������
		template<class _RV>
		_Self& Calculate(const Matrix<_RV>& _matrix_, std::function<void(_Pt&, const _RV&)> _method_);

		//������ÿһ����һ�������м��� - ��������
		template<class _RV>
		_Self& Calculate(const _RV& _value_, std::function<void(_Pt&, const _RV&)> _method_);

		//������ÿһ�����һ������ - ������
		_Self& Calculate(std::function<void(_Pt&)> _method_);

		//�������� - ���������ÿһ������һ�����
		template<class _RV>
		_RV Count(_RV _original_value_, std::function<void(_RV&, const _Ty&)> _method_) const;

		//�������� - ��ȡ������ĳһ��ĸ���
		size_t Count(const _Ty& _value_) const;

	public:		/* �����λ���� */

		//������
		template<class _RV>
		_Self& operator&=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator&(const Matrix<_RV>& _matrix_);

		//������
		template<class _RV>
		_Self& operator|=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator|(const Matrix<_RV>& _matrix_);

		//�������
		template<class _RV>
		_Self& operator^=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator^(const Matrix<_RV>& _matrix_);

		//����������
		template<class _RV>
		_Self& operator&=(const _RV& _value_);
		template<class _RV>
		auto operator&(const _RV& _value_) const;

		//����������
		template<class _RV>
		_Self& operator|=(const _RV& _value_);
		template<class _RV>
		auto operator|(const _RV& _value_) const;

		//�����������
		template<class _RV>
		_Self& operator^=(const _RV& _value_);
		template<class _RV>
		auto operator^(const _RV& _value_) const;

	public:		/* ����Ļ������� */

		//����ȡ��
		_NSelf operator!() const;

		//����ȡ��
		_NSelf operator-() const;

		//����ȡ����
		_NSelf operator~() const;

		//����ӷ�
		template<class _RV>
		_Self& operator+=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator+(const Matrix<_RV>& _matrix_) const;

		//�������
		template<class _RV>
		_Self& operator-=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator-(const Matrix<_RV>& _matrix_) const;

		//����˷�
		template<class _RV>
		_Self& operator*=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator*(const Matrix<_RV>& _matrix_) const;

		//�����ڻ���
		template<class _RV>
		auto operator%(const Matrix<_RV>& _matrix_) const;

		//���������ӷ�
		template<class _RV>
		_Self& operator+=(const _RV& _value_);
		template<class _RV>
		auto operator+(const _RV& _value_) const;

		//������������
		template<class _RV>
		_Self& operator-=(const _RV& _value_);
		template<class _RV>
		auto operator-(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator-(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//���������˷�
		template<class _RV>
		_Self& operator*=(const _RV& _value_);
		template<class _RV>
		auto operator*(const _RV& _value_) const;

		//������������
		template<class _RV>
		_Self& operator/=(const _RV& _value_);
		template<class _RV>
		auto operator/(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator/(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//��������ȡ��
		template<class _RV>
		_Self& operator%=(const _RV& _value_);
		template<class _RV>
		auto operator%(const _RV& _value_) const;
		template<class _TT, class _RV>
		friend auto operator%(const _RV& _value_, const Matrix<_TT>& _matrix_);

		//�����������
		template<class _RV>
		_Self& Mutiply(const Matrix<_RV>& _matrix_);

		//�����������
		template<class _RV>
		_Self& operator/=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		auto operator/(const Matrix<_RV>& _matrix_) const;

		//������������
		template<class _RV>
		_Self& operator%=(const Matrix<_RV>& _matrix_);
		template<class _RV>
		_Self& Surplus(const Matrix<_RV>& _matrix_);

	public:		/* �����С��б任 */

		//��������
		_Self& RowExchange(size_t _row1_, size_t _row2_);

		//��������
		_Self& ColumnExchange(size_t _column1_, size_t _column2_);

		//��ĳ�г���һ����
		_Self& RowMultiply(size_t _row_, const _Ty& _value_);

		//��ĳ�г���һ����
		_Self& ColumnMultiply(size_t _column_, const _Ty& _value_);

		//��ĳ�м���ĳ�е����ⱶ
		//ע���� row1 ���� value ���� row2
		_Self& RowAdd(size_t _row1_, size_t _row2_, const _Ty& _value_ = _Unit_);

		//��ĳ�м���ĳ�е����ⱶ
		//ע���� column1 ���� value ���� column2
		_Self& ColumnAdd(size_t _column1_, size_t _column2_, const _Ty& _value_ = _Unit_);

	public:		/* ����ʽ������� */

		//�������ļ�
		_Ty Trace() const;

		//�������ľ���ֵ�ļ�
		auto AbsoluteTrace() const;

		//�������ĶԽǻ�
		_Ty Diagonal() const;

		//������������ʽ��ֵ
		_Ty Determinant() const;

		//�����������
		_NSelf Inverse() const;

	public:		/* ������ */

		//��ֵ����
		//��ĳ���ģֵƽ��С����ֵ��Ԫ����Ϊ�õ��ֵ
		_Self& Threshold(std::initializer_list<_Ty> points = { _NSelf::_Zero_ }, const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6);
		
		//�Զ���ֵ����
		//ȥ����С�� ʵ�� �� �鲿
		_Self& AutoThreshold(const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6);

		//������ Frobenius ����
		auto FrobeniusNorm() const;

		//������ ����-����
		auto InfiniteNorm() const;

		//������ 1-����
		auto OneNorm() const;

		//������ 2-����
		auto TwoNorm(const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

	public:		/* ���������ֵ */

		//������ģ�������ֵ��ģ
		//�ݷ� - ͨ���Ͽ�
		_Ty PowerMethod(const decltype(norm(std::declval<_Ty>()))&  max_error = 1e-6) const;

		//������ģ�������ֵ��ģ
		//�������㷨 - ����
		_Ty RayleighQuotientIteration(const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//��ȡ�ſɱ���ת����
		_NSelf JacobiMatrix(size_t idx1, size_t idx2);

		//�ſɱ���ת
		//�������ȡ���������ľ���
		//�޶����Գƾ���
		_Self& JacobiRotatation(size_t idx1, size_t idx2, _NSelf* eig_vecs = nullptr);

		//˫���ſɱȷ���
		//��������ȫ������ֵ
		//�������ȡ���������ľ���
		//�޶����Գƾ���ע�⣺�ǶԳƾ����������ѭ������
		//ע�⣺���ؽ��Ϊ�Խ�Ԫ��ȫΪ����ֵ�ķ��� - ������Ϊ��������
		_NSelf BilateralJacobiMethod(_NSelf* eig_vecs = nullptr, const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//������ֵ����������
		_CSelf Eigvalues(_CSelf* eig_vecs = nullptr, const decltype(norm(std::declval<_Ty>())) & max_error = 1e-6);

	public:		/* LU�ֽ� */

		//�þ�����и�˹��Ԫ
		//���ò�����Ԫ��
		_Self& GaussianElimination();

		//�þ�����и�˹-������Ԫ
		_Self& GaussJordanElimination();

		//�þ������ LU �ֽ�
		//ע�⣺���ص��� L ������� �� U ����
		void LUDecomposition(_NSelf& _Linv_, _NSelf& _U_) const;

	public:		/* QR�ֽ� */

		//Gram - Schmidt ������ ������������
		//ʵ���п���ǰ k ���Ѿ�������������ʱ��ָ��ǰ��������������Ĭ��Ϊ0
		_Self& GramSchmidtOrthogonalization(_NSelf* _R_ = nullptr, size_t _column_start_ = 0);

		//��ȡ Householder �任����
		//��Ҫָ�����ĸ�λ����Ϊ��׼λ�ã������ܽ���Ԫ�������Ԫ��ȫ����ȥ��������
		_NSelf HouseholderVector(size_t _row_, size_t _column_, bool erase_column = true, bool erase_back = true);

		//�� Householder ���� v ���ɾ��� H ����ھ���
		//��Ҫ�ṩ v ����Ч���ִ��ĸ�λ�ÿ�ʼ �Լ� �����е���Ч���ִ��Ŀ�ʼ
		_Self& HouseholderLeft(const _NSelf& _v_, _Ip _v_range_ = { 0,-1 }, _Ip _m_range_ = { 0,-1 }, bool erase_column = true);

		//�� Householder ���� v ���ɾ��� H �ҳ��ھ���
		//��Ҫ�ṩ v ����Ч���ִ��ĸ�λ�ÿ�ʼ �Լ� �����е���Ч���ִ��Ŀ�ʼ
		_Self& HouseholderRight(const _NSelf& _v_, _Ip _v_range_ = { 0,-1 }, _Ip _m_range_ = { 0,-1 }, bool erase_column = true);

		//Householder�任
		//�����趨��ʼ��
		_Self& HouseholderTransformation(size_t _start_row_ = 0);

		//��ȡGivens�任����
		_NSelf GivensMatrix(size_t _column_, size_t _row_use_, size_t _row_erase_);

		//��ȡ˫��Givens�任����
		_NSelf BilateralGivensMatrix(size_t row1, size_t row2, size_t column1, size_t column2);

		//���Givens�任����
		_Self& GivensLeft(const _NSelf& _givens_matrix_, size_t _row1_, size_t _row2_);

		//�ҳ�Givens�任����
		_Self& GivensRight(const _NSelf& _givens_matrix_, size_t _column1_, size_t _column2_);

		//����Givens�任
		//��Ҫָ���Եڼ��У�����һ����ȥ��һ��
		_Self& Givens(size_t _column_, size_t _row_use_, size_t _row_erase_);
		
		//Givens�任
		//�����趨��ʼ��
		_Self& GivensTransformation(size_t _start_row_ = 0);

		//�þ������ QR �ֽ�
		void QRDecomposition(_NSelf& _Q_, _NSelf& _R_, bool full = true) const;

	public:		/* ���ȷֽ� */

		//�Ծ��������ȷֽ�
		void FullRankDecomposition(_NSelf& _F_, _NSelf& _G_) const;

		//�����
		//��Ҫָ��Ŀǰ�����Ƕ���
		//ע������������������
		_Self& ExtendBase(size_t _rank_);

	public:		/* ����ֽ� */

		//�Ծ���������ֽ�
		void SchurDecomposition(_NSelf& _T_, _NSelf* _U_ = nullptr,const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

	public:		/* ����ֵ�ֽ� */

		//�Ծ���������ֵ�ֽ�
		//�ֽ�õ� A = US(V^T)
		//���� A �� m*n ���� U �� m*m �������� S �� m*n �Խ��� V �� n*n ��������
		//���� S �����ȡ�� V �� U ����ѡ���ȡ
		//U��V ͬʱ���ڣ����ȼ��� V�������Ҫ���ȼ��� U�����ȶԾ������ת��
		void SVDDecomposition(_NSelf& _S_, _NSelf* _V_ = nullptr, _NSelf* _U_ = nullptr,
			const decltype(norm(std::declval<_Ty>()))& max_error = 1e-6) const;

		//��α�����
		_NSelf PseudoInverse() const;

	public:		/* ��������������� */

		//�� Hessenberg ��
		_Self& UpperHessenbergTransformation();

		//˫�Խǻ�
		_Self& Bidiagonalization();

		//���Խǻ�
		_Self& Tridiagonalization();

	public:		/* ����Ԥ���� */

		//�Զ����ȫΪ 0 ���к���
		//���Ի�ȡ������� �к���
		_Self& ZeroReduction(const decltype(norm(std::declval<_Ty>()))& thresh_val = 1e-6,
			Matrix<size_t>* rows_clear = nullptr, Matrix<size_t>* column_clear = nullptr);

		//�����׼��
		//�ɻ�ȡ��ֵ�ͱ�׼��
		_Self& Standardization(_Ty* _mean_ = nullptr, _Ty* _standard_deviation_ = nullptr);

		//�����һ��
		//�ɻ�ȡ����ϵ��
		_Self& Normalization(_Ty* _Coe = nullptr);

		//��ȡ����ϵ�������ŵ� rmin * rmax = 1��
		auto ScalingCoefficient() const;
	};

	//�������;���
	template<class _Ty>
	using RMatrix = Matrix<typename std::reference_wrapper<_Ty>>;

	//��������
	typedef Matrix<bool> BoolMatrix;
	typedef RMatrix<bool> BoolRMatrix;

	//��������
	typedef Matrix<size_t> IndexMatrix;
	typedef RMatrix<size_t> IndexRMatrix;

	//��������
	template<class _Ty>
	using ComplexMatrix = Matrix<std::complex<_Ty>>;
	template<class _Ty>
	using ComplexRMatrix = RMatrix<std::complex<_Ty>>;

	EasYMatrix_Head(EMSelf _Ty)
		_Default_ = _Ty();

	EasYMatrix_Head(EMSelf _Ty)
		_Zero_ = _Ty();

	//�궨�� _EasYMatrix_NO_UNIT_ ����ȡ��Ĭ�ϵ�λԪ�����ã����ǵ� _Ty(1) �����޷�ʵ�֣�
#ifndef _EasYMatrix_NO_UNIT_

	EasYMatrix_Head(EMSelf _Ty)
		_Unit_ = _Ty(1);

#endif 
	
#ifdef _IOSTREAM_
	//���������
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
		const char* PreText = "{[";			//�������ǰ������ı�
		const char* PostText = "]}";		//��������������ı�

		const char* RowPreText = " [";		//�������һ��ǰ������ı�
		const char* RowPostText = "],\n";	//�������һ�к�������ı�

		const char* ColumnText = ", ";		//�������ÿ�м�������ı�

		size_t OutLength = 10;				//������� - ���ڵ��� iomanip ����Ч
	}

	//���ƾ��������ʽ��ȫ�ֱ���
	EasYMatrix_IOFormat;

	//��������
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

	//�������� Matrix<double> �ĵ�λ����
	Matrix<double> operator""I(unsigned long long _Dim)
	{
		Matrix<double> result;
		result.SetIdentity(_Dim);
		return result;
	}

	//�� _Pt ����ת�� _Ty ����
	EasYMatrix_Head(constexpr EMSelf _Ty&)
		PtCast(_Pt& ptv)
	{
		if constexpr (is_reference_wrapper_v<_Pt>)
			return ptv.get();
		return ptv;
	}

	//Ϊ form �����ڴ�
	EasYMatrix_Head(void) 
		_Allocate_(size_t _size_)
	{
		std::allocator<_Pt> alloc;
		form = alloc.allocate(_size_);
		capacity = _size_;
	}

	//�ͷ� form ���ڴ�
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
	* Ϊ����� form ����һ���µ��ڴ�ռ�
	* ����ʹ�����ڴ���������з���
	* 
	* ����ʵ�ֵķ����Ǵ���һ���µ��ڴ�
	* �� _to_set_value_ Ϊ�������£���Ὣ�������ص��Ĳ��ָ��ƹ�ȥ������ _value_ �����ص����ָ�ֵ
	*/
	EasYMatrix_Head(void) 
		_NewForm_(size_t _row_, size_t _column_, const _Ty& _value_, bool _to_set_value_)
	{
		//���������л������ֵ
#ifdef _DEBUG
		if (_to_set_value_ && is_reference_wrapper_v<_Tt>)
		{
#ifdef _IOSTREAM_
			std::cerr << "EasYMatrix - NewForm - RMatrix can not be assgined to default value!" << std::endl;
#endif
			throw _to_set_value_;
		}
#endif

		//��ȫ��ͬ��û��Ҫ���·���
		if (row == _row_ && column == _column_)
			return;

		//��ȡ�����ڴ�ռ��С
		size_t _CapacityNeed = _row_ * _column_;

		if (form == nullptr)
		{
			//û�о���ֱ�Ӵ����¾���
			if (_row_ > 0 && _column_ > 0)
			{
				_Allocate_(_CapacityNeed);
				row = _row_;
				column = _column_;
				
				//���� _to_set_value_ ������ѡ���Ƿ���и�ֵ
				//���벻�����������
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
			//������������һΪ��ֱ�����óɿվ���
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
				//ֻ�е���ǰ�ڴ�������ʱ�����·���
				if (_CapacityNeed > capacity)
					_Allocate_(_CapacityNeed),
					to_free = true;

				//���� _to_set_value_ ������ѡ���Ƿ���и�ֵ
				//���벻�����������
				if constexpr (!is_reference_wrapper_v<_Tt>)
				{
					if (_to_set_value_)
					{
						auto write_ptr = form;		//дָ��
						auto read_ptr = temp_form;	//��ָ��

						//�������� size_t ��Ҫ�������ѭ����ʹ��
						size_t min_row = row < _row_ ? row : _row_,
							min_column = column < _column_ ? column : _column_;
						size_t _ori_row_add_ = column - min_column,
							_new_row_add_ = _column_ - min_column;

						//�����ص�����
						for (size_t i = 0; i < min_row; i++,
							read_ptr += _ori_row_add_,
							write_ptr += _new_row_add_)
							for (size_t j = 0; j < min_column; j++)
								*write_ptr++ = *read_ptr++;

						//Ϊ���ò��ָ�ֵ���ұߣ�
						write_ptr = form + min_column;
						for (size_t i = 0; i < min_row; i++, write_ptr += min_column)
							for (size_t j = min_column; j < _column_; j++)
								*write_ptr++ = _value_;

						//Ϊ���ò��ָ�ֵ���±ߺ����±ߣ�
						write_ptr -= min_column;
						for (size_t i = min_row; i < _row_; i++)
							for (size_t j = 0; j < _column_; j++)
								*write_ptr++ = _value_;
					}
				}
				else
				{
					//�������ͱ�Ȼ�´���ص�����
					auto write_ptr = form;		//дָ��
					auto read_ptr = temp_form;	//��ָ��

					//�������� size_t ��Ҫ�������ѭ����ʹ��
					size_t min_row = row < _row_ ? row : _row_,
						min_column = column < _column_ ? column : _column_;
					size_t _ori_row_add_ = column - min_column,
						_new_row_add_ = _column_ - min_column;

					//�����ص�����
					for (size_t i = 0; i < min_row; i++,
						read_ptr += _ori_row_add_,
						write_ptr += _new_row_add_)
						for (size_t j = 0; j < min_column; j++)
							*write_ptr++ = *read_ptr++;
				}

				//���ó��µ������������ͷ�ԭ������ռ�õ��ڴ�
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

	//�ͷŵ� form ռ�õ��ڴ棬���� form ��Ϊ��ָ��
	//�൱�ڰѾ����Ϊ�վ���
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

	//ͨ��ָ�롢���������������ƾ���
	//���ǵ���ͬ���͵�ת�����������˺���ģ��
	EasYMatrix_Head(template<class _RV> void)
		 _CopyForm_(_RV* _array_, size_t _row_, size_t _column_)
	{
		size_t _CapacityNeed = _row_ * _column_;
		if (_array_ != nullptr && _row_ > 0 && _column_ > 0)
		{
			//����Ϊ�µ������������������µ��ڴ�ռ�
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
				_Allocate_(_CapacityNeed);

			//��ʵ�൱�ڰ� _array_ ������������� form ���������
			//����������Ϊ����û��������˸��������
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

	//debugģʽ�±���
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
		//����������ܵ��ô˺���
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
		//����������ܵ��ô˺���
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
			//����Ϊ�µ������������������µ��ڴ�ռ�
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
				_Allocate_(_CapacityNeed);

			//��ʵ�൱�ڰ� _array_ ������������� form ���������
			//����������Ϊ����û��������˸��������
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

	//�ú�������ʼ������
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

	//���󿽱�
	EasYMatrix_Head(EMSelf _NSelf) 
		Copy()
	{
		_NSelf _result = *this;
		return _result;
	}

	//��ʵֻ�ǽ���������ʹ�õĵ�ַ
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
		//����������ܵ��ô˺���
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
			//����Ϊ�µ������������������µ��ڴ�ռ�
			size_t ori_size = row * column;
			this->row = _row_;
			this->column = _column_;
			if (_CapacityNeed > capacity)
			{
				//��¼ԭ���ı������
				auto temp_form = this->form;
				size_t _cap = this->capacity;

				//���·����ڴ�
				this->form = nullptr;
				_Allocate_(_CapacityNeed);

				//ֻ�е����·����ڴ�ʱ���п���
				auto write_ptr = this->form;
				auto read_ptr = temp_form;
				for (size_t i = 0; i < ori_size; i++)
					*write_ptr++ = *read_ptr++;

				//������ԭ����form
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
		//����������ܵ��ô˺���
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - Reshape - RMatrix can not be assgined to value!");

		//�����������Ĳ����ж��Ȼ�� Reshape
		size_t new_size = _row_ * _column_;
		size_t ori_size = this->Size();
		size_t over_size = new_size > ori_size ? (new_size - ori_size) : 0;
		Reshape(_row_, _column_);

		//��������Ĳ����� _value_ ���
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

		//������Ԫ����Ϊͬһ��ֵ
		for (size_t i = 0; i < _size_; i++)
			PtCast(*write_ptr++) = _value_;

		return *this;
	}

	EasYMatrix_Head(EMSelf _Self&)
		SetIdentity(size_t _dim_) noexcept
	{
		//��ֹ�������͵��øú���
		static_assert(!is_reference_wrapper_v<_Tt>, "EasYMatrix - SetIdentity - RMatrix can not be changed to identity!");

		_NewForm_(_dim_, _dim_, _Default_, false);
		SetValue(_NSelf::_Zero_);

		auto write_ptr = form;
		size_t _row_add_ = 1 + _dim_;

		//�Խ��߱�Ϊ��λԪ
		for (size_t i = 0; i < _dim_; i++, write_ptr += _row_add_)
			*write_ptr = _NSelf::_Unit_;

		return *this;
	}

	EasYMatrix_Head(template<class _Pred> EMSelf _Self&)
		SetRandom(_Pred pf) noexcept
	{
		auto write_ptr = form;
		size_t _size_ = row * column;
		
		//ÿ��Ԫ�ض�ͨ��ȡ�����������ע�� _Ty(rand()) �����Ƿ�Ϸ�
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

	//��һ�������ȡ�����
	template<class _Tt>
	template<class _RV, class _Mt>
	Matrix<_Mt> Matrix<_Tt>::_Index_(const Matrix<_RV>& _idx_matrix_) const
	{
		//�ж������������Ƿ���ͬ
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

	//�������еķ���Ԫ�����滻�����Ԫ�ذ�˳���滻
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
			//����Ƿ���Ԫ
			if (*ori_read_ptr++ != _NSelf::_Zero_)
			{
				//Ѱ���滻��Ŀ
				PtCast(*write_ptr++) = *read_ptr++;
				rpl_leave--;
			}
		}

		return result;
	}

	//����һ������Ըþ����������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		Mask(const Matrix<_RV>& _kernel_matrix_)
	{
		return Calculate<_RV>(_kernel_matrix_, 
			[&](_Tt& a, const _RV& b) {if (b == Matrix<_RV>::_NSelf::_Zero_) { PtCast(a) = _NSelf::_Zero_; }});
	}

	/*
	* ��������������ȡ����Ϊ���������һ���¾���
	* ���Ⱥ�˳��֮�֣������������ 1 2 0 2 3 ����ɵ��¾�����ϵ��µ��ж�Ӧԭ����Ҳ�� 1 2 0 2 3
	* 
	* ������Ϊ�õ������������Ե�һ��Ҫ�Ƚ���������װ�����飬Ȼ�����ѭ������¾���
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		Row(const size_t* _index_list_, size_t _size_) const
	{
		Matrix<_RV> _result;
		if (_size_ > 0)
		{
			//�����¾���׼������
			_result._NewForm_(_size_, column, _Default_, false);

			auto write_ptr = _result.form;
			for (size_t i = 0; i < _size_; i++)
			{
				_DebugError_(_index_list_[i] >= row || column == 0, "Row", "Row is Out of range!");

				//���¾���ǰ�ж�Ӧԭ����Ŀ����
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
	* �������������ȡ�������¾���ͬ��
	* ���ｫ������ȡ�������¾���
	* ˳��Ϊ������
	* 
	* ʵ�ַ������л�����ͬ
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		Column(const size_t* _index_list_, size_t _size_) const
	{
		Matrix<_RV> _result;
		if (_size_ > 0)
		{
			//�����¾���׼������
			_result._NewForm_(row, _size_, _Default_, false);

			for (size_t i = 0; i < _size_; i++)
			{
				_DebugError_(_index_list_[i] >= column || row == 0, "Column", "Column is Out of range!");

				//���¾���ǰ�ж�Ӧԭ����Ŀ����
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
	* ��ȥ��Ӧ�У������¾���
	* ���������ظ����У����Ǹ�ֻ����һ��Ч����һ����
	*
	* �����漰��������������ͬ��Ҫ�Ƚ����������������
	* Ȼ�󽫲������������������������¾���ֵ��
	*
	* ����Ҫ�����ǣ���Ϊ���ǲ��ܷ������ڴ��١��������ڴ�
	* ����ֻ�ܱ��������У����������Ƿ��ܹ����䣨��Ȼ��
	* ������������ȿ���Ҫ��ȥ�����У�ʵ���ϵģ�
	* Ȼ������¾���Ĵ�С
	* �����ε���ȥ���У���û���ε����и��¾���ֵ
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		RowCrossOut(const size_t* _index_list_, size_t _size_) const
	{
		//��Ҫ�µ�����
		std::allocator<size_t> alloc;
		size_t* new_index = alloc.allocate(_size_);

		//����ԭ����
		auto copy_ptr = new_index;
		auto save_ptr = new_index;
		for (size_t i = 0; i < _size_; i++)
			*copy_ptr++ = *_index_list_++;

		//������������������õ��ǿ�������
		std::sort(new_index, new_index + _size_);

		//��һ��ѭ���ǿ���ʵ�����ж�����Ҫ����ȥ
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
			//�����¾���׼������
			_result._NewForm_(_real_size_, column, _Default_, false);

			auto write_ptr = _result.form;
			for (size_t i = 0; i < row; i++)
			{
				//����ȥ���У���������
				if (i == *new_index)
				{
					while (*++new_index == i);//����ʹ�ò����ܹ������ظ����У�����û�ж��������
					continue;
				}

				//û���ε����У����и���
				auto read_ptr = this->form + i * column;
				for (size_t j = 0; j < column; j++)
					*write_ptr++ = *read_ptr++;
			}
		}

		//Ҫ���¹����������ͷ�
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
	* ��ȥ��Ӧ�У������¾���
	* ���������ظ����У����Ǹ�ֻ����һ��Ч����һ����
	*
	* ����ʵ�ַ����뻮ȥ����һ����
	*/
	EasYMatrix_Head(template<class _RV> Matrix<_RV>)
		ColumnCrossOut(const size_t* _index_list_, size_t _size_) const
	{
		//��������鲻�ܱ�ʹ�ã���Ҫ�µ�����
		std::allocator<size_t> alloc;
		size_t* new_index = alloc.allocate(_size_);

		//����ԭ����
		auto copy_ptr = new_index;
		auto save_ptr = new_index;
		for (size_t i = 0; i < _size_; i++)
			*copy_ptr++ = *_index_list_++;

		//������������������õ��ǿ�������
		std::sort(new_index, new_index + _size_);

		//����ʵ�����ж�����Ҫ����ȥ
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
			//�����¾���׼������
			_result._NewForm_(row, _real_size_, _Default_, false);

			size_t _temp_times_ = 0;//���ڼ�¼�¾����Ƶ��ڼ���
			for (size_t i = 0; i < column; i++)
			{
				//����ȥ���У���������
				if (i == *new_index)
				{
					while (*++new_index == i);
					continue;
				}

				//û���ε����У����и���
				auto write_ptr = _result.form + _temp_times_++;
				auto read_ptr = this->form + i;
				for (size_t j = 0; j < row; j++, write_ptr += _real_size_, read_ptr += column)
					*write_ptr = *read_ptr;
			}
		}

		//Ҫ���¹����������ͷ�
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
	* �����ν�ȡ���󹹳��¾���
	* �������ṩ���϶���������С��������Լ����¶���������С�������
	*
	* ʵ�ַ������������ȡ����ͬ����С���¾���
	* ���ƹ�ȥ����
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

		//�����¾���׼������
		Matrix<_RV> _result;
		_result.row = _row_end_ - _row_start_;
		_result.column = _column_end_ - _column_start_;
		_result._Allocate_(_result.row * _result.column);

		//����Ӧ���ָ��Ƶ��¾�����
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
	* ʵ�־����ƴ�ӣ�ƴ�ӷ�ʽ��
	* | A B |   -
	*           A
	*           B
	*           -
	* �����ַ�ʽ�������ҡ����£�
	* ���ɵڶ������� left_right ���ƣ�Ĭ��Ϊtrue��
	* 
	* ʵ�ַ�����Ϊ����С�����¾���Ȼ����и���
	* �� if ���Ʒ�֧
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

			//����ƴ��
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

			//����ƴ��
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

	//����ת��
	EasYMatrix_Head(EMSelf _NSelf)
		Transpose() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(column, row);

		auto write_ptr = _result.form;
		auto read_ptr = this->form;

		//�ߵ����н��и�ֵ����
		for (size_t i = 0; i < row; i++, write_ptr = _result.form + i)
			for (size_t j = 0; j < column; j++, write_ptr += row)
				*write_ptr = *read_ptr++;

		return _result;
	}

	//����ת��
	EasYMatrix_Head(EMSelf _NSelf)
		ConjugateTranspose() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(column, row);

		auto write_ptr = _result.form;
		auto read_ptr = this->form;

		//�ߵ����н��и�ֵ����
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

	//���·�ת
	EasYMatrix_Head(EMSelf _NSelf)
		FlipUpAndDown() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(row, column);

		//��λ�����һ��
		auto write_ptr = _result.form + (row - 1) * column;
		auto read_ptr = this->form;

		//ÿ�θ���������ǰһ��
		for (size_t i = 0; i < row; i++, write_ptr -= (column + column))
			for (size_t j = 0; j < column; j++)
				*write_ptr++ = *read_ptr++;

		return _result;
	}

	//���ҷ�ת
	EasYMatrix_Head(EMSelf _NSelf)
		FlipLeftAndRight() const
	{
		if (form == nullptr)
			return _NSelf();

		_NSelf _result(row, column);

		//��λ����һ��
		auto write_ptr = _result.form + column;
		auto read_ptr = this->form;

		//ÿ�θ�����������һ�еĺ�һ��
		for (size_t i = 0; i < row; i++, write_ptr += (column + column))
			for (size_t j = 0; j < column; j++)
				*--write_ptr = *read_ptr++;

		return _result;
	}

	//��ʱ����ת n �� 90��
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
			//��ʱ����ת 1 �� 90��
			_result.Reshape(column, row);

			//��λ�����һ��
			auto help_ptr = _result.form + (column - 1) * row;
			auto write_ptr = help_ptr;

			//ÿ�θ������������һ�ж�Ӧ�Ǹ�Ԫ��
			for (size_t i = 0; i < row; i++, write_ptr = ++help_ptr)
				//ÿ����ǰ��һ��
				for (size_t j = 0; j < column; j++, write_ptr -= row)
					*write_ptr = *read_ptr++;

			break;
		}
		case 2:
		{
			//��ʱ����ת 2 �� 90��
			_result.Reshape(row, column);

			//��λ�����һ��Ԫ�غ�
			auto write_ptr = _result.form + row * column;

			//������
			for (size_t i = 0; i < row; i++)
				for (size_t j = 0; j < column; j++)
					*--write_ptr = *read_ptr++;

			break;
		}
		case 3:
		{
			//��ʱ����ת 3 �� 90��
			_result.Reshape(column, row);

			//��λ����һ�����һ��
			auto help_ptr = _result.form + (column - 1);
			auto write_ptr = help_ptr;

			//ÿ�θ�����������һ�ж�Ӧ�Ǹ�Ԫ��
			for (size_t i = 0; i < row; i++, write_ptr = --help_ptr)
				//ÿ��������һ��
				for (size_t j = 0; j < column; j++, write_ptr += row)
					*write_ptr = *read_ptr++;

			break;
		}
		}

		return _result;
	}

	/*
	* ��Ӧ�ȽϾ����ÿ��ֵ
	* ����Ϊtrue��������Ϊfalse
	*/
	template<class _Tt> template<class _RV, class _BL> BoolMatrix Matrix<_Tt>::
		Compare(const Matrix<_RV>& _matrix_, std::function<_BL(const _Tt&, const _RV&)> _method_) const
	{
		//�ж������������Ƿ���ͬ
		_DebugError_(this->row != _matrix_.row, "Compare", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Compare", "The column of two matrices must be same!");

		BoolMatrix result(row, column);

		//�ж϶�Ӧÿ��Ԫ��
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

		//�ж϶�Ӧÿ��Ԫ��
		auto read_ptr = this->form;
		auto write_ptr = result.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _method_(*read_ptr++, _value_);

		return result;
	}

	//����
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

	//������
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

	//����
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

	//С��
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

	//���ڵ���
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

	//С�ڵ���
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

	//������ĳһ��������һ������Ķ�Ӧ���������
	EasYMatrix_Head (template<class _RV> EMSelf _Self&)
		Calculate(const Matrix<_RV>& _matrix_, std::function<void(_Pt&, const _RV&)> _method_)
	{
		//�ж������������Ƿ���ͬ
		_DebugError_(this->row != _matrix_.row, "Calculate", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Calculate", "The column of two matrices must be same!");

		//��������
		auto write_ptr = this->form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++, *read_ptr++);

		return *this;
	}

	//������ĳһ����һ�������м���
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		Calculate(const _RV& _value_, std::function<void(_Pt&, const _RV&)> _method_)
	{
		//��������
		auto write_ptr = this->form;
		size_t _size_ = this->row * this->column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++, _value_);

		return *this;
	}

	//������ÿһ�����һ������ - ������
	EasYMatrix_Head(EMSelf _Self&)
		Calculate(std::function<void(_Pt&)> _method_)
	{
		//��ÿһ�����һ������
		auto write_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++)
			_method_(*write_ptr++);
		return *this;
	}

	//�������� - ���������ÿһ������һ�����
	EasYMatrix_Head(template<class _RV> _RV)
		Count(_RV _original_value_, std::function<void(_RV&, const _Ty&)> _method_) const
	{
		auto read_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++)
			_method_(_original_value_ , *read_ptr++);
		return _original_value_;
	}

	//�������� - ��ȡ������ĳһ��ĸ���
	EasYMatrix_Head(size_t) 
		Count(const _Ty& _value_) const
	{
		return Count<size_t>(0, [&](size_t& i, const _Pt& j) {if (j == _value_)i++; });
	}

	//������
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

	//������
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

	//�������
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

	//����������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator&=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {PtCast(a) &= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator&(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()& typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result &= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator&(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ & _value_;
	}

	//����������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator|=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {a |= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator|(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() | typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result |= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator|(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ | _value_;
	}

	//�����������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator^=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Pt& a, const _RV& b) {a ^= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator^(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() ^ typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result ^= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator^(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ ^ _value_;
	}

	//����ȡ��
	EasYMatrix_Head(EMSelf _NSelf)
		operator!() const
	{
		//����
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = !a; });
		return _result;
	}

	//����ȡ��
	EasYMatrix_Head(EMSelf _NSelf)
		operator-() const
	{
		//����
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = -a; });
		return _result;
	}

	//����ȡ����
	EasYMatrix_Head(EMSelf _NSelf)
		operator~() const
	{
		//����
		_NSelf _result = *this;
		_result.Calculate([](_Ty& a) {a = conj(a); });
		return _result;
	}

	/*
	* ����ӷ�
	* ���� form ��Ӧ���
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
	* �������
	* ���� form ��Ӧ���
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
	* ����˷�
	* ������Ӽ�����ͬ��Ҫ�õ�����ѭ������Ϊ���ݶ���ÿһ������һ����ͣ�
	*/
	EasYMatrix_Head(template<class _RV> inline auto)
		operator*(const Matrix<_RV>& _matrix_) const
	{
		_DebugError_(this->column != _matrix_.row, "operator*", "Left matrix's column is not equal to right matrix's row!");

		//�����¾���
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>
			_result(this->row, _matrix_.column, 
				Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>::_Zero_);
		
		//����¾����ÿһ��
		auto write_ptr = _result.form;
		auto left_read_ptr = this->form;
		auto right_read_ptr = _matrix_.form;
		for (size_t i = 0; i < this->row; i++, right_read_ptr = _matrix_.form, write_ptr += _result.column)
			for (size_t k = 0; k < this->column; k++, left_read_ptr++, write_ptr -= _result.column)
				for (size_t j = 0; j < _matrix_.column; j++)
					*write_ptr++ += PtCast(*left_read_ptr) * _matrix_.PtCast(*right_read_ptr++);	//����˷�����

		return _result;
	}

	//�����ڻ�
	EasYMatrix_Head(template<class _RV> inline auto)
		operator%(const Matrix<_RV>& _matrix_) const
	{
		_DebugError_(this->row != _matrix_.row, "Dot Product", "The row of two matrices must be same!");
		_DebugError_(this->column != _matrix_.column, "Dot Product", "The column of two matrices must be same!");

		//������������Ԫ
		decltype(typename remove_reference_wrapper<_Tt>::type() * typename remove_reference_wrapper<_RV>::type())
			_result =
			std::is_same<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type()),
			typename remove_reference_wrapper<_Tt>::type>::value ?
			_NSelf::_Zero_ : Matrix<_RV>::_NSelf::_Zero_;

		//�������ڻ�
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

	//���������ӷ�
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator+=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a += b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator+(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() + typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result += _value_;
	}

	template<class _Ty,class _RV> 
	inline auto operator+(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ + _value_;
	}
	
	//������������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator-=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a -= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator-(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() - typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result -= _value_;
	}

	template<class _Ty, class _RV>
	auto operator-(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(_Ty() + _RV())> _result(_matrix_.row, _matrix_.column);

		//�������
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_  - *read_ptr++;

		return _result;
	}

	//���������˷�
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator*=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a *= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator*(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type()* typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result *= _value_;
	}

	template<class _Ty, class _RV>
	inline auto operator*(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		return _matrix_ * _value_;
	}

	//������������
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator/=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a /= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator/(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() / typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result /= _value_;
	}

	template<class _Ty, class _RV>
	auto operator/(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(_RV() / _Ty())> _result(_matrix_.row, _matrix_.column);

		//�������
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_ / *read_ptr++;

		return _result;
	}

	//��������ȡ��
	EasYMatrix_Head(template<class _RV> EMSelf _Self&)
		operator%=(const _RV& _value_)
	{
		return Calculate<_RV>(_value_, [](_Ty& a, const _RV& b) {a %= b; });
	}

	EasYMatrix_Head(template<class _RV> inline auto)
		operator%(const _RV& _value_) const
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(typename remove_reference_wrapper<_Tt>::type() % typename remove_reference_wrapper<_RV>::type())>
			_result = *this;
		return _result %= _value_;
	}

	template<class _Ty, class _RV>
	auto operator%(const _RV& _value_, const Matrix<_Ty>& _matrix_)
	{
		//׼�����ڴ�ռ�
		Matrix<decltype(_RV() % _Ty())> _result(_matrix_.row, _matrix_.column);

		//����ȡ��
		auto write_ptr = _result.form;
		auto read_ptr = _matrix_.form;
		size_t _size_ = _result.row * _result.column;
		for (size_t i = 0; i < _size_; i++)
			*write_ptr++ = _value_ % *read_ptr++;

		return _result;
	}

	//�����������
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

	//�����������
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

	//������������
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

	//��������
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

	//��������
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

	//��ĳ�г���һ����
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

	//��ĳ�г���һ����
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

	//��ĳ�м���ĳ�е����ⱶ
	//ע���� row1 ���� value ���� row2
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

	//��ĳ�м���ĳ�е����ⱶ
	//ע���� column1 ���� value ���� column2
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

	//�������ļ�
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

	//�������ľ���ֵ�ļ�
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

	//�������ĶԽǻ�
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

	//������������ʽ��ֵ
	EasYMatrix_Head(EMSelf _Ty) 
		Determinant() const
	{
		_DebugError_(row != column, "Determinant", "The matrix must be square!");

		//ԭ��
		//ͨ����˹��Ԫ������ʽ��Ϊ��������
		//������ʽֵ���ǶԽ��߳˻�

		_NSelf Det = *this;
		Det.GaussianElimination();
		return Det.Diagonal();
	}

	//�����������
	EasYMatrix_Head(EMSelf _NSelf)
		Inverse() const
	{
		_DebugError_(row != column, "Inverse", "The matrix must be square!");

		//ԭ��
		//���� B = [A I]
		//ͨ����˹Լ����Ԫ������ C = [I H]
		//���� H ���� A �������

		//��һ�� - ƴ�Ӿ��� B
		_NSelf I, A;
		I.SetIdentity(row);
		A = *this;
		auto B = A.Splicing(I);
		
		//�ڶ��� - �Ծ��� B ���� ��˹Լ����Ԫ
		B.GaussJordanElimination();

		return I;
	}

	//��ֵ����
	//��ĳ���ģֵС����ֵ��Ԫ����Ϊ�õ��ֵ
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

	//�Զ���ֵ����
	//ȥ����С�� ʵ�� �� �鲿
	EasYMatrix_Head(EMSelf _Self&)
		AutoThreshold(const decltype(norm(std::declval<_Ty>()))& thresh_val)
	{
		auto temp_form = this->form;
		size_t _size_ = row * column;
		if constexpr (IsComplex_<_Ty>::value)
		{
			//����ȥ����Сֵ����Сʵ�����鲿
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
			//ʵ��ֻȥ����Сֵ
			for (size_t i = 0; i < _size_; i++, temp_form++)
			{
				auto norm_v = norm(PtCast(*temp_form));
				if (norm_v < thresh_val * thresh_val)
					PtCast(*temp_form) = _NSelf::_Zero_;
			}
		}
		return *this;
	}

	//������ Frobenius ����
	EasYMatrix_Head(auto)
		FrobeniusNorm() const
	{
		using T = decltype(abs(std::declval<_Ty>()));
		T result = T();

		//��ȡ���ű���
		auto scaling_coe = ScalingCoefficient();

		//����Ԫ�ص�ƽ����
		auto read_ptr = this->form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			result += norm(PtCast(*read_ptr) * scaling_coe);

		//����
		return sqrt(result) / scaling_coe;
	}

	//������ ����-����
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
				//��֤�ӵ��Ǿ���ֵ
				temp += abs(*read_ptr);
			}

			//��֤ȡ����
			if (abs(temp) > abs(max))
				max = temp;
		}
		return max;
	}

	//������ 1-����
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

				//��֤�ӵ��Ǿ���ֵ
				temp += abs(*y);
			}

			//��֤ȡ����
			if (abs(temp) > abs(max))
				max = temp;
		}
		return max;
	}

	//������ 2-����
	EasYMatrix_Head(auto)
		TwoNorm(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		return sqrt(real((this->ConjugateTranspose() * (*this)).PowerMethod(max_error)));
	}

	//�������������ֵ��ģ
	//�õ����ݷ�
	EasYMatrix_Head(EMSelf _Ty)
		PowerMethod(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "PowerMethod", "The matrix must be square!");

		_NSelf xn(column, 1, _NSelf::_Unit_);
		_Ty last_dist_v = _NSelf::_Unit_ + _NSelf::_Unit_,
			dist_v = _NSelf::_Unit_;

		//���С��һ��ֵ��ֹͣѭ��
		while (norm(_NSelf::_Unit_ - dist_v / last_dist_v) > max_error * max_error)
		{
			last_dist_v = dist_v;
			xn = (*this) * xn;
			dist_v = xn.InfiniteNorm();
			xn /= dist_v;
		}

		return dist_v;
	}

	//�������������ֵ��ģ
	//�õ��������̵���
	EasYMatrix_Head(EMSelf _Ty)
		RayleighQuotientIteration(const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "RayleighQuotientIteration", "The matrix must be square!");

		_NSelf xn(column, 1, _NSelf::_Unit_), MA;
		_RSelf MB;
		_Ty last_dist_v = _NSelf::_Unit_ + _NSelf::_Unit_,
			dist_v = _NSelf::_Unit_;

		//���С��һ��ֵ��ֹͣѭ��
		while (norm(_NSelf::_Unit_ - dist_v / last_dist_v) > max_error * max_error)
		{
			//����������λ����
			last_dist_v = dist_v;
			dist_v = xn % ((*this) * xn) / (xn % xn);

			//��ⷽ����
			MA = (*this) - dist_v * _NSelf().SetIdentity(row);
			MB = MA.Splicing(xn);
			MB.GaussJordanElimination();

			//�õ��µĽ��
			xn /= xn.InfiniteNorm();
		}

		return dist_v;
	}

	//��ȡ�ſɱ���ת����
	EasYMatrix_Head(EMSelf _NSelf)
		JacobiMatrix(size_t idx1, size_t idx2)
	{
		_DebugError_(std::max(idx1, idx2) >= std::min(row, column), "JacobiMatrix", "Index is out of range!");

		//����ǰ�ò���
		_Ty tau = ((*this)(idx1, idx1) - (*this)(idx2, idx2)) / ((*this)(idx1, idx2) + (*this)(idx2, idx1));
		_Ty t = tau == _NSelf::_Zero_ ? _NSelf::_Unit_ : (tau / (abs(tau) * (abs(tau) + sqrt(_NSelf::_Unit_ + tau * tau))));
		_Ty cos_v = _NSelf::_Unit_ / sqrt(_NSelf::_Unit_ + t * t), sin_v = t * cos_v;

		//�����ſɱ���ת����
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

		//������Ҫ������
		if constexpr (IsComplex_<_Ty>::value)
			jacobi_mat *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return jacobi_mat;
	}

	//�ſɱ���ת
	//�޶����Գƾ���
	EasYMatrix_Head(EMSelf _Self&) 
		JacobiRotatation(size_t idx1, size_t idx2, _NSelf* eig_vecs)
	{
		_DebugError_(std::max(idx1, idx2) >= std::min(row, column), "JacobiRotatation", "Index is out of range!");

		//�����ſɱȾ���
		_NSelf jacobi_mat = JacobiMatrix(idx1, idx2);
		
		//1.�б任 - ���
		GivensLeft(jacobi_mat, idx1, idx2);

		//2.�б任 - �ҳ�
		GivensRight(jacobi_mat.ConjugateTranspose(), idx1, idx2);

		//3.��������������������ڣ�
		if (eig_vecs)
			_DebugError_(std::max(idx1, idx2) >= std::min(eig_vecs->row, eig_vecs->column), "JacobiRotatation", "Index is out of range!(For eig_vecs)"),
			eig_vecs->GivensRight(jacobi_mat.ConjugateTranspose(), idx1, idx2);

		return *this;
	}

	//˫���ſɱȷ���
	//��������ȫ������ֵ
	//�޶����Գƾ���ע�⣺�ǶԳƾ����������ѭ������
	EasYMatrix_Head(EMSelf _NSelf)  
		BilateralJacobiMethod(_NSelf* eig_vecs, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		//����Ƿ�Ϊ�Գ���
		//���Խ�Ԫ���Ƿ�Ϊ0
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

		//���Ҫ��ȡ�����������ȱ�Ϊ��λ����
		if (eig_vecs)
			eig_vecs->SetIdentity(dim);

		//��������
		result.Normalization(&scaling_coe);
		//���б�����ת
		bool had_find = false;
		do
		{
			had_find = false;

			for (size_t i = 0; i < (dim - 1); i++)
			{
				for (size_t j = (i + 1); j < dim; j++)
				{
					//��ֵ���󣬽�����ת
					if (abs(result(i, j)) > max_error)
					{
						had_find = true;
						result.JacobiRotatation(i, j, eig_vecs);
					}
				}
			}

			//��ת������������ת
		} while (had_find);

		//ȫ���ھ��ȷ�Χ�ڣ�����ѭ�������������ȥ
		result.AutoThreshold(max_error);

		//�Ŵ��ȥ
		return result *= _NSelf::_Unit_ / scaling_coe;
	}

	//������ֵ����������
	EasYMatrix_Head(EMSelf _CSelf)
		Eigvalues(_CSelf* eig_vecs, const decltype(norm(std::declval<_Ty>()))& max_error)
	{
		_DebugError_(row != column, "Eigvalues", "The matrix must be square!");

		const size_t dim = this->row;

		_CSelf result = *this;
		result.SchurDecomposition(result, eig_vecs, max_error);

		if (eig_vecs)
		{
			//������������ ���� U �� T
			//�� T = X * D * X^(-1)
			//�� A = U * T * T^(-1) = (U * X) * D * (U * X)^(-1)
			//X ���󷨣�T�б任ͬʱD�б任�����ձ�� T * X = X * D
			//������հ� Eigen �������
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

		//��ȡ����ֵ����
		for (size_t i = 0; i < dim; i++)
			for (size_t j = i + 1; j < dim; j++)
				result(i, j) = _CSelf::_Zero_;

		return result;
	}

	//�þ�����и�˹��Ԫ
	//���õ��ǲ�����Ԫ��ȥ��
	EasYMatrix_Head(EMSelf _Self&)
		GaussianElimination()
	{
		//��ȡ����ĳһ�е���Ԫ������λ��
		auto get_first_of_row = [&](size_t _row_) -> size_t
		{
			for (size_t i = 0; i < this->Columns(); i++)
				if ((*this)(_row_, i) != _NSelf::_Zero_)
					return i;
			return this->Columns();
		};
		
		//������任Ϊ�����;���
		size_t skip_cols = 0;
		for (size_t i = 0; i < this->Rows() - 1; i++)
		{
			//��֤��ǰ�е���Ԫ�����������������е���ǰ��
			size_t now_first = get_first_of_row(i);
			if (now_first > i + skip_cols)
			{
				//Ѱ��Ԫ�ر��Լ���ǰ��
				size_t best_row = i;
				size_t best_first = now_first;
				for (size_t j = i + 1; j < this->Rows(); j++)
				{
					size_t this_first = get_first_of_row(j);
					if (this_first == this->Columns()) continue;	//��ֹ�������� this_first ����
					if (this_first < best_first ||
						(this_first == best_first && 
							norm((*this)(j, this_first)) > norm((*this)(best_row, best_first))))
					{
						best_row = j;
						best_first = this_first;
					}
				}

				//�����Լ�ǰ�Ļ���
				now_first = best_first;
				skip_cols = now_first - i;
				this->RowExchange(i, best_row);
			}

			//�������ȫΪ0������ѭ��
			if (now_first == this->Columns())
				break;

			//���������и��е�Ԫ��
			_Ty _tempv_ = _NSelf::_Unit_ / (*this)(i, now_first);
			for (size_t j = i + 1; j < this->Rows(); j++)
			{
				this->RowAdd(j, i, -_tempv_ * (*this)(j, now_first));
				(*this)(j, now_first) = _NSelf::_Zero_;
			}
		}

		return *this;
	}

	//�þ�����и�˹������Ԫ
	EasYMatrix_Head(EMSelf _Self&)
		GaussJordanElimination()
	{
		//��ȡ����ĳһ�е���Ԫ������λ��
		auto get_first_of_row = [&](size_t _row_) -> size_t
		{
			for (size_t i = 0; i < this->Columns(); i++)
				if ((*this)(_row_, i) != _NSelf::_Zero_)
					return i;
			return this->Columns();
		};

		//��һ�� - ���и�˹��Ԫ
		this->GaussianElimination();

		//�ڶ��� - ��ÿһ����Ԫ����1
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

		//������ - ��Ϊ���յĸ�˹��Ԫ����
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

	//�þ������ LU �ֽ�
	EasYMatrix_Head(void)
		LUDecomposition(_NSelf& _Linv_, _NSelf& _U_) const
	{
		//ԭ��
		//�� LU = A
		//������� B = [A I] = [LU I]
		//��B���и�˹��Ԫ�ɵ� C = [U L-1]

		//��һ�� - ���� B
		_Linv_.SetIdentity(this->Rows());
		_U_ = *this;
		_RSelf B = _U_.Splicing(_Linv_);

		//�ڶ��� - ��˹��Ԫ
		B.GaussianElimination();
	}

	//Gram - Schmidt ������ ������������
	//���õ��ǸĽ��汾��
	EasYMatrix_Head(EMSelf _Self&)
		GramSchmidtOrthogonalization(_NSelf* _R_, size_t _column_start_)
	{
		_DebugError_(_column_start_ > column, "GramSchmidtOrthogonalization", "The column_start is out of range!");

		if (_R_) _R_->Reshape(column, column, _NSelf::_Zero_);
		_RSelf result_col, back_col;
		_Ty norm_v;

		//Gram - Schmidt ������ ��ʵ��
		for (size_t k = 0; k < column; k++)
		{
			//��ȡ�������ǰ��
			result_col = Column({ k });

			//�����������Ž��д���
			if (k >= _column_start_)
			{
				//������еķ���
				norm_v = result_col.FrobeniusNorm();
				if (_R_) (*_R_)(k, k) = norm_v;

				//����Ϊ0��˵��������أ�����ѭ��
				if (norm_v == _NSelf::_Zero_) break;

				//����ǰ�б�׼��
				result_col *= _NSelf::_Unit_ / norm_v;
			}

			//������м�ȥ��ǰ�з���
			//�ӷ����������ֿ�ʼ
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

	//��ȡ Householder �任����
	//��Ҫָ�����ĸ�λ����Ϊ��׼λ�ã������ܽ���Ԫ�������Ԫ��ȫ����ȥ��������
	EasYMatrix_Head(EMSelf _NSelf) 
		HouseholderVector(size_t _row_, size_t _column_, bool erase_column, bool erase_back)
	{
		_DebugError_(_row_ >= row, "HouseholderVector", "The row is out of range!");
		_DebugError_(_column_ >= column, "HouseholderVector", "The column is out of range!");

		//��ȡ������
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

		//��ȡ�����еķ���
		auto norm_v = erase_column ?
			part_col.SubMatrix(erase_back ? _row_ : 0, erase_back ? row : _row_ + 1, 0, 1).FrobeniusNorm()
			: part_col.SubMatrix(0, 1, erase_back ? _column_ : 0, erase_back ? column : _column_ + 1).FrobeniusNorm();

		//ȷ�� alpha ����
		if(part_col[erase_column ? _row_ : _column_] != _NSelf::_Zero_)
			part_col[erase_column ? _row_ : _column_] +=
				norm_v * (part_col[erase_column ? _row_ : _column_]
				/ abs(part_col[erase_column ? _row_ : _column_]));
		
		//�����淶��
		part_col.Normalization();

		return part_col;
	}

	//�� Householder ���� v ���ɾ��� H ����ھ���
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

		//��ȡ���� v �ķ���ƽ��
		_Ty norm_v = _NSelf::_Zero_;
		for (size_t i = _v_range_.first; i < _v_range_.second; i++)
			norm_v += norm(_v_[i]);
		
		//������أ�����
		if (norm_v == _NSelf::_Zero_)
			return *this;
		
		//��ʣ���Ӿ��󲿷ֽ��б任
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

	//�� Householder ���� v ���ɾ��� H �ҳ��ھ���
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

		//��ȡ���� v �ķ���ƽ��
		_Ty norm_v = _NSelf::_Zero_;
		for (size_t i = _v_range_.first; i < _v_range_.second; i++)
			norm_v += norm(_v_[i]);

		//������أ�����
		if (norm_v == _NSelf::_Zero_)
			return *this;

		//��ʣ���Ӿ��󲿷ֽ��б任
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

	//Householder�任
	EasYMatrix_Head(EMSelf _Self&)
		HouseholderTransformation(size_t _start_row_)
	{
		_DebugError_(_start_row_ >= row, "HouseholderTransformation", "The row is out of range!");

		_NSelf v;
		size_t max_rank = (row - _start_row_) < column ? (row - _start_row_) : column;

		for (size_t k = 0; k < max_rank; k++)
		{
			//��ȡ���� v
			v = HouseholderVector(k + _start_row_, k);

			//��ʣ���Ӿ��󲿷ֽ��б任
			HouseholderLeft(v, k + _start_row_, k);
		}

		return *this;
	}

	//��ȡGivens�任����
	EasYMatrix_Head(EMSelf _NSelf)
		GivensMatrix(size_t _column_, size_t _row_use_, size_t _row_erase_)
	{
		_DebugError_(_column_ >= column, "GivensMatrix", "The column is out of range!");
		_DebugError_(_row_use_ >= row, "GivensMatrix", "The row is out of range!");
		_DebugError_(_row_erase_ >= row, "GivensMatrix", "The row is out of range!");

		//���� cos �� sin ֵ
		_Ty sin_v, cos_v;
		//���������ֹ���������
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

		//���� Givens ����
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

		//������Ҫ������
		if constexpr (IsComplex_<_Ty>::value)
			result *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return result;
	}

	//��ȡ˫��Givens�任����
	EasYMatrix_Head(EMSelf _NSelf)
		BilateralGivensMatrix(size_t row1, size_t row2, size_t column1, size_t column2)
	{
		_DebugError_(row1 >= row || row2 >= row, "GivensMatrix", "The row is out of range!");
		_DebugError_(column1 >= column || column2 >= column, "GivensMatrix", "The column is out of range!");
		
		//���� cos �� sin ֵ
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

		//����˫�� Givens ����
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

		//������Ҫ������
		if constexpr (IsComplex_<_Ty>::value)
			result *= _NSelf::_Unit_ / sqrt(norm(sin_v) + norm(cos_v));

		return result;
	}

	//���Givens�任����
	EasYMatrix_Head(EMSelf _Self&) 
		GivensLeft(const _NSelf& _givens_matrix_, size_t _row1_, size_t _row2_)
	{
		_DebugError_(_givens_matrix_.row != 2 || _givens_matrix_.column != 2, "GivensLeft", "Givens matrix must be 2 x 2!");
		_DebugError_(_row1_ >= row || _row2_ >= row, "GivensLeft", "The row is out of range!");

		//��ȡҪ�õ�������
		_RSelf my_use, my_erase;
		_NSelf vec_use, vec_erase;
		my_use = this->Row({ _row1_ });
		my_erase = this->Row({ _row2_ });
		vec_use = my_use;
		vec_erase = my_erase;

		//������
		my_use.Assgin(_givens_matrix_(0, 0) * vec_use + _givens_matrix_(0, 1) * vec_erase);
		my_erase.Assgin(_givens_matrix_(1, 0) * vec_use + _givens_matrix_(1, 1) * vec_erase);

		return *this;
	}

	//�ҳ�Givens�任����
	EasYMatrix_Head(EMSelf _Self&) 
		GivensRight(const _NSelf& _givens_matrix_, size_t _column1_, size_t _column2_)
	{
		_DebugError_(_givens_matrix_.row != 2 || _givens_matrix_.column != 2, "GivensRight", "Givens matrix must be 2 x 2!");
		_DebugError_(_column1_ >= column || _column2_ >= column, "GivensRight", "The column is out of range!");

		//��ȡҪ�õ�������
		_RSelf my_use, my_erase;
		_NSelf vec_use, vec_erase;
		my_use = this->Column({ _column1_ });
		my_erase = this->Column({ _column2_ });
		vec_use = my_use;
		vec_erase = my_erase;

		//������
		my_use.Assgin(_givens_matrix_(0, 0) * vec_use + _givens_matrix_(1, 0) * vec_erase);
		my_erase.Assgin(_givens_matrix_(0, 1) * vec_use + _givens_matrix_(1, 1) * vec_erase);

		return *this;
	}

	//����Givens�任
	EasYMatrix_Head(EMSelf _Self&)
		Givens(size_t _column_, size_t _row_use_, size_t _row_erase_)
	{
		_DebugError_(_column_ >= column, "Givens", "The column is out of range!");
		_DebugError_(_row_use_ >= row, "Givens", "The row is out of range!");
		_DebugError_(_row_erase_ >= row, "Givens", "The row is out of range!");

		//��ȡ Givens ����
		auto gmat = GivensMatrix(_column_, _row_use_, _row_erase_);

		//������
		GivensLeft(gmat, _row_use_, _row_erase_);

		return *this;
	}

	//Givens�任
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

	//�þ������ QR �ֽ�
	EasYMatrix_Head(void)
		QRDecomposition(_NSelf& _Q_, _NSelf& _R_, bool full) const
	{
		if (full)
		{
			//ԭ��
			//�� QR = A
			//���� B = [QR I]
			//�� B ���� Householder �任
			//���յõ� B = [R Q^(-1)]
			//�ٶ� Q^(-1) ת�ñ�õ� Q

			//��һ�� - ���� B
			_Q_.SetIdentity(this->Rows());
			_R_ = *this;
			_RSelf _B_ = _R_.Splicing(_Q_);

			//�ڶ��� - Householder �任
			_B_.HouseholderTransformation();

			//������ - �� Q ת��
			_Q_ = _Q_.ConjugateTranspose();
		}
		else
		{
			//������ QR�ֽ⣬��ʹ��ʩ��������������
			_Q_ = *this;
			_Q_.GramSchmidtOrthogonalization(&_R_);
		}
	}

	//�Ծ��������ȷֽ�
	EasYMatrix_Head(void)
		FullRankDecomposition(_NSelf& _F_, _NSelf& _G_) const
	{
		//�ȰѾ���ͨ����˹��Ԫ��Ϊ���ݾ���
		_NSelf temp_matrix = *this;
		temp_matrix.GaussianElimination();

		//���ڼ�¼�����޹ص�������
		Matrix<size_t> use_column(column, 1);
		size_t use_idx = 0;

		//ͨ�������б任����������߽��Ƶ�λ���ģ��
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

		//�۲�õ�F��G����
		if (_row > 0)
		{
			_F_ = Column(use_column);
			_G_ = temp_matrix.SubMatrix(_row, column, true);
		}
	}

	//����� - ��������
	EasYMatrix_Head(EMSelf _Self&)
		ExtendBase(size_t _rank_)
	{
		_DebugError_(row < _rank_ || column < _rank_, "ExtendBase", "The rank is out of range!");

		//��ȡ����ĳһ�е���Ԫ������λ��
		auto get_first_of_row = [](const _NSelf& mat, size_t _row_) -> size_t
		{
			for (size_t i = 0; i < mat.Columns(); i++)
				if (mat(_row_, i) != _NSelf::_Zero_)
					return i;
			return mat.Columns();
		};

		_NSelf temp_mat;
		Matrix<size_t> record_vec;

		//��һ�� - ת�ò���Ϊ�����;���
		temp_mat = this->Transpose();
		temp_mat.GaussianElimination();

		//�ڶ��� - �ҳ�ÿһ�У���һ������Ԫ������
		record_vec.Reshape(_rank_, 1);
		for (size_t i = 0; i < _rank_; i++)
			record_vec[i] = get_first_of_row(temp_mat, i);
		
		//������ - ����Ϊ�걸��
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

	//�Ծ���������ֽ�
	EasYMatrix_Head(void)
		SchurDecomposition(_NSelf& _T_, _NSelf* _U_, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		_DebugError_(row != column, "SchurDecomposition", "The matrix must be square!");

		_T_ = *this;
		if(_U_)_U_->SetIdentity(row);

		//��������
		_Ty scaling_coe;
		_T_.Normalization(&scaling_coe);

		//������ Hessenberg ��
		_NSelf v;
		for (size_t k = 1; k < row; k++)
		{
			//��ȡ���� v
			v = _T_.HouseholderVector(k, k - 1);

			//��˲��ҳ� Householder ����
			_T_.HouseholderLeft(v, k, k - 1).HouseholderRight(v, k, 0);
			if(_U_)_U_->HouseholderRight(v, k, 0);
		}

		//��������߽�
		size_t i_begin = 0, i_end = row - 1;

		//�����¸��Խ��ߵ��²�
		//�˺����ǳ���Ҫ�����ڴ��;��󣬸ú�������Ч��ֹ����������ǵ��ۻ�Ǩ�Ƶ�������
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
		* ������
		*/
		auto Error_Analyze = [&]()
		{
		ERROR_AGAIN:

			//������ϣ�ȡ������
			if (i_end == 0)
				return;

			//��������������ж��
			size_t res = i_end;
			while (res)
			{
				_Ty error_p = abs(_T_(res - 1, res - 1)) + abs(_T_(res, res));

				if (abs(_T_(res, res - 1)) < max_error)
					break;
				res--;
			}
			i_begin = res;

			//����� 1x1 �� 2x2
			//ֱ���ų����ٴη���
			if (i_begin == i_end)
			{
				i_end--;
				goto ERROR_AGAIN;
			}
			else if (i_begin + 1 == i_end)
			{
				//��Ҫ�жϸ� 2x2 �����Ƿ���ʵ����ֵ��
				//����������Ҫ�����ⲽ�ж�
				_Ty trace_v = _T_(i_begin, i_begin) + _T_(i_end, i_end),
					det_v = _T_(i_begin, i_begin) * _T_(i_end, i_end) - _T_(i_begin, i_end) * _T_(i_end, i_begin),
					delta_v = trace_v * trace_v - _Ty(4) * det_v;

				//�� real ������
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
		
		//QR ����
		while (i_end > 0)
		{
			//λ����
			_Ty dist_v = _T_(i_end, i_end);
			for (size_t i = i_begin; i <= i_end; i++)
				_T_(i, i) -= dist_v;

			//Givens��ת ʵ�� QR����
			for (size_t i = i_begin; i < i_end; i++)
			{
				_NSelf givens_mat = _T_.GivensMatrix(i, i, i + 1);
				_T_.GivensLeft(givens_mat, i, i + 1);
				_T_.GivensRight(givens_mat.ConjugateTranspose(), i, i + 1);
				if(_U_)_U_->GivensRight(givens_mat.ConjugateTranspose(), i, i + 1);
			}

			//�����¸��Խ��ߵ��²�
			clear_low_diag();

			//����λ����
			for (size_t i = i_begin; i <= i_end; i++)
				_T_(i, i) += dist_v;
			
			//������� - ѡ��������
			Error_Analyze();
		}

		//��������ǲ���
		for (size_t i = 2; i < row; i++)
			for (size_t j = 0; j < i - 1; j++)
				_T_(i, j) = _NSelf::_Zero_;

		//�����¸��Խ���
		for (size_t i = 1; i < row; i++)
			if(abs(_T_(i, i - 1)) < max_error)
				_T_(i, i - 1) = _NSelf::_Zero_;

		//�Ŵ��ȥ
		_T_ *= _NSelf::_Unit_ / scaling_coe;
	}

	//�Ծ���������ֵ�ֽ�
	EasYMatrix_Head(void)
		SVDDecomposition(_NSelf& _S_, _NSelf* _V_, _NSelf* _U_, const decltype(norm(std::declval<_Ty>()))& max_error) const
	{
		//�д����е����
		if (this->column > this->row)
		{
			auto tmp_mat = this->ConjugateTranspose();
			tmp_mat.SVDDecomposition(_S_, _U_, _V_, max_error);
			_S_ = _S_.ConjugateTranspose();
			return;
		}

		//�Ƿ���ж��ηֽ�
		bool is_snd_decom = _V_ != nullptr && _U_ != nullptr;

		//��һ�����ڷֽ�ľ���
		_NSelf* fst_dec_mat = _V_ ? _V_ : _U_;

		//1.���е�һ�������ֽ� - ��Ȼ�õ� S^2 ����
		_NSelf evd_mat = (fst_dec_mat == _U_) ? (*this * this->ConjugateTranspose()) : (this->ConjugateTranspose() * *this);
		//������������Ԫ
		IndexMatrix dc_vec;
		evd_mat.ZeroReduction(max_error, &dc_vec);
		//�ſɱȷ���������ֵ
		evd_mat = evd_mat.BilateralJacobiMethod(fst_dec_mat, max_error);

		//2.�� S^2 �ĶԽ�Ԫ�ؿ����õ� S
		//����������
		size_t max_rank = row > column ? column : row;
		if (dc_vec.Size())
		{
			//�����������У�Ҫ���� max_rank
			if (max_rank > evd_mat.Rows())
				max_rank = evd_mat.Rows();

			//����Ҫ���� V
			_V_->Reshape(column, column, _NSelf::_Zero_);
			for (size_t i = 0; i < dc_vec.Size(); i++)
				(*_V_)(column - 1 - i, column - 1 - i) = _NSelf::_Unit_;
		}

		_S_.Reshape(this->row, this->column, _NSelf::_Zero_);
		for (size_t i = 0; i < max_rank; i++)
			_S_(i, i) = sqrt(evd_mat(i, i));
		
		//2.5.�����������У���Ҫ���� V ��˳��
		for(size_t i = 0; i < dc_vec.Size(); i++)
			for (size_t j = dc_vec[i]; j < evd_mat.Rows() + i; j++)
				_V_->RowExchange(j, j + 1).ColumnExchange(j, j + 1);

		//3.���еڶ��ηֽ� - �����Ҫ�Ļ�
		if (is_snd_decom)
		{
			//�� AV = US
			//�� (AV){nxn} = [s1 * u1 ,s2 * u2 ... ,sn * un] �ɽ�� u1,u2 ... un
			//Ȼ������ U���ٽ�������������

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
			
			//�������������
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

	//��α�����
	EasYMatrix_Head(EMSelf _NSelf) 
		PseudoInverse() const
	{
		//���� SVD �ֽ�
		_NSelf U, S, V;
		this->SVDDecomposition(S, &V, &U);

		//�� S �ĶԽ���Ԫ��ȡ����
		size_t max_rank = std::min(S.Rows(), S.Columns());
		for (size_t i = 0; i < max_rank; i++)
		{
			if (S(i, i) != _NSelf::_Zero_)
				S(i, i) = _NSelf::_Unit_ / S(i, i);
			else
				break;
		}

		//���������
		return V * S.ConjugateTranspose() * U.ConjugateTranspose();
	}

	//�� Hessenberg ��
	EasYMatrix_Head(EMSelf _Self&)
		UpperHessenbergTransformation()
	{
		_DebugError_(row != column, "UpperHessenbergTransformation", "The matrix must be square!");

		_NSelf v;
		for (size_t k = 1; k < row; k++)
		{
			//��ȡ���� v
			v = HouseholderVector(k, k - 1);

			//��˲��ҳ� Householder ����
			HouseholderLeft(v, k, k - 1).HouseholderRight(v, k, 0);
		}

		return *this;
	}

	//˫�Խǻ�
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

	//���Խǻ�
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

	//�Զ����ȫΪ 0 ���к���
	EasYMatrix_Head(EMSelf _Self&)
		ZeroReduction(const decltype(norm(std::declval<_Ty>()))& thresh_val, Matrix<size_t>* rows_clear, Matrix<size_t>* column_clear)
	{
		if (Empty())return *this;

		Matrix<size_t> index_vec;
		size_t real_size;

		//��ȥ��
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

		//��ȥ��
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

	//�����׼��
	//�ɻ�ȡ��׼����ֵ�ͱ�׼������
	EasYMatrix_Head(EMSelf _Self&)
		Standardization(_Ty* _mean_, _Ty* _standard_deviation_)
	{
		if (Empty())return *this;

		_Ty m = _NSelf::_Zero_, v = _NSelf::_Zero_;

		//��һ��
		//��ֹ����
		_Ty coe;
		Normalization(&coe);

		//��������
		auto read_ptr = form;
		size_t _size_ = row * column;
		_Ty _div = _NSelf::_Unit_ / _Ty(_size_);
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			m += *read_ptr,
			v += *read_ptr * *read_ptr;
		m *= _div;
		v = _div * sqrt(v);

		//�����׼��
		*this -= m;
		*this *= _NSelf::_Unit_ / v;

		//��������
		m /= coe;
		v /= coe;

		//���� ��ֵ �� ����
		if (_mean_) *_mean_ = m;
		if (_standard_deviation_) *_standard_deviation_ = v;

		return *this;
	}

	//�����һ��
	//�ɻ�ȡ����ϵ��
	EasYMatrix_Head(EMSelf _Self&)
		Normalization(_Ty* _Coe)
	{
		if (Empty())return *this;

		_Ty max_v = _NSelf::_Zero_;

		//�ҳ�ģ���ֵ
		auto read_ptr = form;
		size_t _size_ = row * column;
		for (size_t i = 0; i < _size_; i++, read_ptr++)
			if (abs(*read_ptr) > abs(max_v))
				max_v = *read_ptr;

		//��������
		max_v = _NSelf::_Unit_ / max_v;
		*this *= max_v;

		if (_Coe) *_Coe = max_v;
		return *this;
	}

	//��ȡ����ϵ�������ŵ�ָ�����ֶԳƣ�
	EasYMatrix_Head(auto)
		ScalingCoefficient() const
	{
		using T = decltype(norm(std::declval<_Ty>()));
		T max_norm = T(1), min_norm = T(1), now_norm;

		//Ѱ�����ģ����ģ��С��ֵ
		auto read_ptr = form;
		size_t _size_ = row * column;
		//����δ��ֵ
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