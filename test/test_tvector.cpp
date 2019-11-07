#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)//скопированный вектор равен первому
{
	TVector<int> v1(10);
	v1[4] = 12;
	TVector<int> v2(v1);
	EXPECT_EQ(v2, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)//скопированный вектор имеет собственную память
{
	TVector<int> v1(10);
	v1[4] = 12;
	TVector<int> v2(v1);
	EXPECT_NE(&v2, &v1);
}

TEST(TVector, can_get_size)//можем получить размер
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)//может получить начальный индекс
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)//можно установить и получить элемент
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)//бросает, когда задан элемент с отрицательным индексом
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-2]=5);
}

TEST(TVector, throws_when_set_element_with_too_large_index)//бросает, когда установлен элемент со слишком большим индексом
{
	ASSERT_ANY_THROW(TVector<int> v(4, MAX_VECTOR_SIZE +1));
}

TEST(TVector, can_assign_vector_to_itself)//может назначить вектор себе
{
	TVector<int> v(10);
	v[0] = 321;
	v = v;
	EXPECT_EQ(v, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)//можно назначить векторы одинакового размера
{
	TVector<int> v1(10);
	TVector<int> v2(10);
	v1[1] = 5;
	v2 = v1;
	EXPECT_EQ(v2, v1);
}

TEST(TVector, assign_operator_change_vector_size)//назначить оператор изменения размера вектора
{
	TVector<int> v1(4), v2(7);
	for (int i = 0; i < 4; i++)
	v1[i] = 10;
	v2 = v1;
	EXPECT_EQ(4, v2.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size)//можно назначить векторы разного размера
{
	TVector<int> v1(5), v2(6);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, compare_equal_vectors_return_true)//сравнить равные векторы вернуть true
{
	TVector<int> v1(5), v2(5);
	v1[2] = 3;
	v2[2] = 3;
	ASSERT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)//сравнить вектор с самим собой вернуть true
{
	TVector<int> v(5);
	v[2] = 3;
	ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)//векторы с разным размером не равны
{
	TVector<int> v1(3), v2(5);
	ASSERT_FALSE(v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)//можно прибавить скаляр к вектору
{
	TVector<int> v1(3), v2(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 1;
	EXPECT_EQ(v1, v2 + 1);
}

TEST(TVector, can_subtract_scalar_from_vector)//можно вычесть скаляр из вектора
{
	TVector<int> v1(3), v2(3);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 3;
		v2[i] = 4;
	}
	EXPECT_EQ(v1, v2 - 1);
}

TEST(TVector, can_multiply_scalar_by_vector)//Можно умножить скаляр на вектор
{
	TVector<int> v1(3), v2(3);
	for (int i = 0; i < 3; i++)
	{
		v1[i] = 9;
		v2[i] = 3;
	}
	EXPECT_EQ(v1, v2 * 3);
}

TEST(TVector, can_add_vectors_with_equal_size)//можно сложить векторы с одинаковым размером
{
	TVector<int> v1(3), v2(3);
	ASSERT_NO_THROW(v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)//Нельзя сложить векторы с разным размером
{
	TVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)//может вычитать векторы с одинаковым размером
{
	TVector<int> v1(3), v2(3);
	ASSERT_NO_THROW(v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)//Нельзя вычитать векторы с разным размером
{
	TVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)//Можно умножать векторы с одинаковым размером
{
	TVector<int> v1(3), v2(3);
	ASSERT_NO_THROW(v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)//Нельзя умножать векторы с разным размером
{
	TVector<int> v1(3), v2(4);
	ASSERT_ANY_THROW(v1 * v2);
}

