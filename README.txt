Se placer dans le répertoire src.

Pour compiler le projet, effectuez la commande make.

Pour lancer les tests, faire la commande "make tests". Plus simplement, pour compiler un fichier, mettre "./parser" suivi du chemin du fichier. Nos fichiers de tests sont dans le répertoire tst.

De même, vous pouvez compiler les fichiers fournis par M. Barthou en lançant la commande tests_barthou.

Cela va générer les codes assembleurs des fichiers tests.
Cela va également afficher le nom du fichier compilé et les éventuelles erreurs.

Nous savons que plusieurs tests ne passent pas. Les principales raisons sont que nous n'avons pas adapté l'utilisation du malloc, et nous ne pouvons pas faire appel à des fonctions externes. 

Nous n'avons pas eu le temps d'implémenter complétement notre extension. Nous pensons avoir géré le dépassement des tableaux, mais pas les types de retour des fonctions. Nous avons préféré avancer au maximum sur le compilateur du pseudo-langage C.

L'assembleur généré correspond à une architecture Ubuntu 12.04 LTS 32bits.
