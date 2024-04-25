4.3:	cfixa:		cflotant:
0.0	0x00000000	0x00000000
-0.0	0x80000000	0x80000000
12.75	0x0000CC00	0x01CC0000

4.4: Contesta:

	1) Quina condició ha de complir el valor inicial de cfixa perquè es produeixi pèrdua de precisió en la conversió que proposa aquesta pràctica?
		La precisió es té en la part decimal. Com que el registre de la coma fixa té destinats 30 bits per a la representació del nombre decimal, en canvi, la coma flotant conté
		només 23 bits. Per tal que es produeixi un error de precisió, és necessari que, entre els dos bits entre els més llunyans que estan inicialitzats a 1, hi hagi com a mínim
		23 bits.
		
	2) Indica un valor de cfiza per al qual es produiria pèrdua de precisió al convertir-lo, i el corresponent valor en coma flotant:
		cfixa: 0x1000CC11	cflotant: 0x47800660
		
	3) En quina setnència concreta del programa en alt nivell es pot produir la pèrdua de precisió?
		La sentència d'alinear i eliminar el bit ocult.
		
	4) Quins dels 4 modes d'arrodoniment que coneixes està portant a la pràctica d'aquest programa de conversió?
		El mètode d'arrodoniment és el truncament.
	
	
	5) El format de coma fixa explicat en aquesta pràctica permet codificar un rang de valors bastant limitat. Indica un número positiu que estigui DINS el rang
	del format de coma flotant de simple precisió (en decimal) però que estigui FORA del rang del format de coma fixa. Indica també quin és el MENOR
	número potència de 2 que compleixi aquesta condició.
		El rang de la coma fixa és: 	[2^(-12), 2^(19)]	(positius)
		El rang de la coma flotant és :	[2^(-23), 2^(129)]	(positius)
		
		Aleshores, el nombre positiu dins del rang del format de la coma flotant i fora del ranfo del format de la coma fixa és 2^(120), la menor potència serà 2^(-13)