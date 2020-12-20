# Cobertura-Vacinal
Técnica de otimização e estruturação de dados utilizando os conceitos de HashMap e arvore AVL.

O portal do DataSUS (http://datasus.saude.gov.br/) divulga várias informações relativas à saúde pública no país.
Entre as informações divulgadas pelo portal, encontram-se os dados de cobertura vacinal em 5570 municípios brasileiros.
O arquivo com a cobertura vacinal nestes municípios está localizado como "filename" no projeto.

O projeto constitui em uma analise das respectivas coberturas vacinais, no qual são mapeadas em um hashmap, como também,
em uma arvore AVL, sem a necessidade de existir a duplicação dos dados nas duas estruturas, e sim, apenas a referência para um único
endereço logico. Consequentemente, diminuindo na metade a necessidade de memoria de programa.
Desse modo, é possível estruturar todos os dados de maneira otimizada realizando buscas individuais em tempo O(1),
como também a listagem em tempo dinâmico em O(log n).

![](https://github.com/FelipeFFerreira/Cobertura-Vacinal/blob/master/gifApresentacao.gif "")
 
