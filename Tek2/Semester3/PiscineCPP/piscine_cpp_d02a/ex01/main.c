int main(void)
{
  t_tree tree = NULL;
  t_tree left_sub_tree;
  unsigned int size;
  unsigned int depth;
  double max;
  double min;

  btree_create_node(&tree, 42.5);
  btree_create_node(&(tree->right), 100);
  btree_create_node(&(tree->left), 20);

  left_sub_tree = tree->left;

  btree_create_node(&(left_sub_tree->left), 30);
  btree_create_node(&(left_sub_tree->right), 5);
  size = btree_get_size(tree);
  depth = btree_get_depth(tree);

  printf(‘‘L’arbre a une taille de %u\n’’, size);
  printf(‘‘L’arbre a une profondeur de %u\n’’, depth);

  max = btree_get_max_value(tree);
  min = btree_get_min_value(tree);

  printf(‘‘Les valeurs de l’arbre vont de %f a %f\n’’, min, max);
  return (0);
}
