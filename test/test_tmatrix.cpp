#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)//скопированная матрица равна исходной
{
	TMatrix<int> m1(5);
	m1[1][2] = 3;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)//скопированная матрица имеет собственную память
{
	TMatrix<int> m1(5);
	m1[2][2] = 4;
	TMatrix <int> m2(m1);
	m2[2][2] = 8;
	EXPECT_NE(m1[2][2], m2[2][2]);
}

TEST(TMatrix, can_get_size)//можем получить размер
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)//можно установить и получить элемент
{
	TMatrix<int> m(5);
	m[2][2] = 7;
	EXPECT_EQ(4, m[2][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)//бросает, когда задан элемент с отрицательным индексом
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[2][-2] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)//бросает, когда установлен элемент со слишком большим индексом
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[2][60] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)//может назначить матрицу себе
{
	TMatrix<int> m(5);
	m[2][2] = 3;
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)//можно назначить матрицы одинакового размера
{
	TMatrix<int> m1(5), m2(5);
	m1[2][2] = 3;
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)//назначить оператор изменения  размера матрицы 
{
	TMatrix<int> m1(5), m2(8);
	m1[2][2] = 3;
	m2 = m1;
	EXPECT_EQ(5, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)//можно назначать матрицы разного размера
{
	TMatrix<int> m1(5), m2(7);
	m1[2][2] = 8;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)//сравнить равные матрицы вернуть true
{
	TMatrix<int> m1(5), m2(5);
	m1[2][2] = 4;
	m2[2][2] = 4;
	ASSERT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)//сравнить матрицу с самой собой вернуть true
{
	TMatrix<int> m(5);
	m[2][2] = 4;
	ASSERT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)//матрицы с разными размерами не равны
{
	TMatrix<int> m1(5), m2(7);
	m1[2][2] = 4;
	m2[2][2] = 4;
	ASSERT_FALSE(m1 == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)//можно складывать матрицы одинакового размера
{
	TMatrix<int> m1(5), m2(5);
	m1[2][2] = 4;
	m2[2][2] = 5;
	ASSERT_NO_THROW(m1 + m2);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)//нельзя складывать матрицы с не равным размером
{
	TMatrix<int> m1(5), m2(8);
	m1[2][2] = 4;
	m2[2][2] = 7;
	ASSERT_ANY_THROW(m1 +m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)//можно вычитать матрицы с одинаковым размером
{
	TMatrix<int> m1(5), m2(5);
	m1[2][2] = 4;
	m2[2][2] = 5;
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)//нельзя вычитать матрицы с разным размером
{
	TMatrix<int> m1(5), m2(8);
	m1[2][2] = 4;
	m2[2][2] = 7;
	ASSERT_ANY_THROW(m1 - m2);
}

