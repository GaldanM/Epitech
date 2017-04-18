/*
** simple_btree.c for Stree in /home/moulin_c/rendu/piscine_cpp_d02a/ex01
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 19:00:33 2015 Galdan MOULINNEUF
** Last update Fri Jan  9 00:42:17 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>
#include	"simple_btree.h"

t_bool		btree_is_empty(t_tree tree)
{
  if (tree == NULL)
    return (TRUE);
  return (FALSE);
}

unsigned int	btree_get_size(t_tree tree)
{
  unsigned int	left = 0;
  unsigned int	right = 0;
  unsigned int	nodes = 1;

  if (tree != NULL)
    {
      left = btree_get_size(tree->left);
      right = btree_get_size(tree->right);
      nodes = nodes + left + right;
      return (nodes);
    }
  return (0);
}

unsigned int	btree_get_depth(t_tree tree)
{
  unsigned int	left;
  unsigned int	right;

  if (tree != NULL)
    {
      left = btree_get_depth(tree->left);
      right = btree_get_depth(tree->right);
      if (left > right)
	return (left + 1);
      return (right + 1);
    }
  return (0);
}

t_bool		btree_create_node(t_tree *node_ptr, double value)
{
  t_tree	tmp;

  if ((tmp = malloc(sizeof(t_tree *))) == NULL)
    return (FALSE);
  tmp->value = value;
  tmp->left = NULL;
  tmp->right = NULL;
  (*node_ptr) = tmp;
  return (TRUE);
}

t_bool		btree_delete_node(t_tree *root_ptr)
{
  if (*root_ptr != NULL)
    {
      btree_delete_node(&(*root_ptr)->left);
      btree_delete_node(&(*root_ptr)->right);
      free(*root_ptr);
      *root_ptr = NULL;
      return (TRUE);
    }
  return (FALSE);
}

double		search_max(t_tree tree, double max)
{
  double	tmp_max;

  if (tree != NULL)
    {
      tmp_max = btree_get_max_value(tree);
      if (tmp_max > max)
	max = tmp_max;
    }
  return (max);
}
double		btree_get_max_value(t_tree tree)
{
  double	max_v;

  if (tree != NULL)
    {
      max_v = tree->value;
      max_v = search_max(tree->right, max_v);
      max_v = search_max(tree->left, max_v);
      return (max_v);
    }
  return (0);
}

double		search_min(t_tree tree, double min)
{
  double	tmp_min;

  if (tree != NULL)
    {
      tmp_min = btree_get_min_value(tree);
      if (tmp_min < min)
	min = tmp_min;
    }
  return (min);
}
double		btree_get_min_value(t_tree tree)
{
  double	min_v;

  if (tree != NULL)
    {
      min_v = tree->value;
      min_v = search_min(tree->right, min_v);
      min_v = search_min(tree->left, min_v);
      return (min_v);
    }
  return (0);
}
