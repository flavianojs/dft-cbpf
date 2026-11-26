# Aula 8 — gabarito do professor (não distribuir)

Notebook dos alunos: `notebooks/aula8_handson.ipynb` (no GitHub e no `dft-cbpf.zip`).
Versão resolvida: `aula8_handson_solucao.ipynb` (fora do repositório; a célula do material lê `MATERIAL` do ambiente, padrão "C").
Todos os números abaixo: QE 6.7 do apt (Ubuntu 24.04 + qe_fix), serial, pseudos PSLibrary 1.0.0 gerados com o ld1.x do 6.7.

## 1. Tutorial: densidade eletrônica do silício (seção 3, não avaliada)

Si da Aula 6 (LDA, Si.pz-vbc, 30 Ry, 6³, a = 10,26 bohr); scf, depois `bands` só em Γ; pp.x.

| grandeza | valor |
| --- | --- |
| E (scf) | −15,85039422 Ry (1 s) |
| autovalores em Γ | −5,88; 6,06 (×3); 8,61 (×3); 9,34 eV |
| n no plano (110) | de 0,0008 (nos núcleos) a 0,086 elétrons/bohr³ (perto do meio da ligação) |
| n ao longo da ligação | 0,0008 → 0,080 → 0,086 → 0,084 (centro) → 0,086 → 0,080 → 0,0008: duas corcovas com um vale raso no centro |
| ∫ n na célula cúbica | 32,00 |
| Γ, bandas 2–4: n(centro da ligação)/máximo na ligação | 1,00 (ligante) |
| Γ, bandas 5–7: n(centro)/máximo na ligação | 0,06 (antiligante; o máximo no plano fica atrás dos átomos, 15 vezes maior que o máximo sobre a ligação) |
| tempo total | ~15 s (cada pp.x < 2 s) |

A seção 3 é um tutorial completo: o aluno só roda e lê, e as explicações abaixo já estão no texto do notebook. Servem de modelo para a etapa 5.6.
- **3.2 (plano):** n(r) é máxima entre os átomos, no meio da ligação Si–Si: carga de ligação, ligação covalente. Nos núcleos n ≈ 0: o pseudopotencial tira os elétrons de caroço (1s, 2s, 2p), e as pseudo-funções de onda 3s/3p não têm os nós de ortogonalização ao caroço; ficam pequenas e suaves dentro do raio de corte. A densidade real (com caroço) seria enorme ali.
- **3.3 (∫ n e 3D):** 32 elétrons: a célula cúbica tem 4 células primitivas, 8 átomos, 4 elétrons de valência cada. Isosuperfície em 0,06: tubos/elipsoides ao longo das ligações, a rede tetraédrica do diamante.
- **3.4 (orbitais em Γ):** Bandas 2–4 (Γ25', topo da valência): carga sobre as ligações, ligante. Bandas 5–7 (Γ15, base da condução em Γ): nó no meio da ligação, carga atrás dos átomos, antiligante. Excitar um elétron através do gap tira carga de estados ligantes e põe em antiligantes: a ligação enfraquece. No 3D com sinal: a banda 5 troca de sinal entre os dois átomos da ligação; a banda 2 não. Somar a degenerescência porque cada estado isolado é uma combinação arbitrária; a soma é invariante e tem a simetria do cristal.


## 2. Perguntas sobre DFT (respostas-modelo)

- **Q1.** O potencial externo é um funcional único da densidade do estado fundamental (a menos de uma constante). Então todas as propriedades do estado fundamental são funcionais de n(r). Basta minimizar E[n] sobre densidades, uma função de 3 variáveis, em vez de lidar com Ψ(r₁, …, r_N).
- **Q2.** O sistema de KS é um sistema auxiliar de elétrons não interagentes com a mesma densidade do sistema real, num potencial efetivo. São tratados exatamente: a energia cinética dos não interagentes T_s, o Hartree e o potencial externo. Só E_xc é aproximado (troca e correlação, mais a correção T − T_s).
- **Q3.** `ecutwfc` define o tamanho da base de ondas planas: |k+G|²/2 < ecut. Mais ondas planas é uma base maior, e pelo princípio variacional a energia só pode descer. A malha k não é uma base: é uma quadratura da integral na ZB, cujo erro pode ter qualquer sinal (não variacional).
- **Q4.** Os elétrons de caroço quase não participam da ligação, e as funções de onda deles (e as de valência, que oscilam perto do núcleo para serem ortogonais ao caroço) exigiriam ondas planas de energia muito alta. O pseudopotencial substitui núcleo e caroço por um potencial suave que reproduz o espalhamento dos elétrons de valência fora de um raio de corte: menos elétrons e um corte bem menor. Pontos extras: transferibilidade; norm-conserving vs ultrasoft.
- **Q5.** Num metal a ocupação salta de 1 para 0 na superfície de Fermi; a integral em k de uma função descontínua converge devagar. O smearing troca o degrau por uma função suave de largura `degauss` (σ). Com σ pequeno demais, a convergência em k é lenta e o SCF instável; com σ grande demais, o resultado se afasta do de σ → 0 (a energia livre F = E − σS se desvia).
- **Q6.** Usar a saída como próxima entrada amplifica os erros: um erro δn volta multiplicado por (1 − λ), com λ da ordem da constante dielétrica, e diverge se λ > 2 ("charge sloshing" em metais e células grandes). `mixing_beta` é a fração da nova densidade misturada à anterior: β pequeno é mais estável e mais lento; o QE usa Broyden com β como passo inicial.
- **Q7.** A densidade (scf) converge rápido em k; a DOS precisa resolver estruturas em energia (picos, bordas, van Hove) e pede malhas mais densas. O nscf diagonaliza o Hamiltoniano fixo numa malha densa sem refazer o SCF. Tetraedros interpolam ε_nk linearmente e integram a δ analiticamente: bordas e gaps corretos sem um parâmetro de alargamento. O smearing alarga e pode pôr estados no gap.
- **Q8.** Não diretamente. O gap fundamental é I − A, uma diferença de energias totais. Mesmo com o funcional exato, E_g = E_g^KS + Δ_xc (descontinuidade derivativa). Em LDA/GGA, Δ_xc = 0 e a curvatura de E(N) está errada (auto-interação), então o gap de KS subestima: Si 0,52 contra 1,17 eV. A forma das bandas é confiável; o valor do gap, não.

## 3. Projeto: valores de referência

Critério usado: 1 meV/átomo na energia total. Pseudos: `src/pseudos/*-rrkjus_psl.1.0.0.UPF`, ecutrho = 8 × ecutwfc.

### Al (metal)
- Valência: 3 elétrons. Corte sugerido no pseudo: 29 Ry.
- ecutwfc: 30 Ry já dá 0,8 meV/átomo (referência 120 Ry). A convergência é rápida.
- Malha k (MV 0,02 Ry): oscila. Malhas centradas: 8³ 4,5; 10³ 16; 12³ 5,9; 16³ 4,6 meV/átomo. Deslocadas: 12³ 0,9; 16³ 1,1 meV/átomo (referência 20³ deslocada). Bom aluno: nota a oscilação, prefere malha deslocada e densa (16³ ou mais), comenta o papel de σ.
- a₀ (PBE) = 4,039 Å (7,632 bohr), −0,3% em relação a 4,050 Å. B₀ ≈ 78 GPa (exp. ≈ 76 GPa). Ajuste cúbico e Birch–Murnaghan concordam em 0,0001 Å.
- Bandas: tipo elétron livre, bandas cruzando E_F. DOS(E_F) ≈ 0,40 estados/eV/célula. DOS integrada em E_F: 3,00.
- Löwdin: s 0,93, p 2,03 (spilling 0,014).
- Erros comuns: occupations = 'fixed' (pw.x reclama ou converge errado); ler "gap" de um metal.

- 5.6 (densidade, Al): quase uniforme entre os átomos, ≈ 0,03 elétrons/bohr³ (a média 3 e/célula dá 0,027); pico de 0,077 no núcleo (o pseudo 3s não tem nó); mínimo 0,011. ∫ n na célula cúbica = 12,00. Estado ocupado mais alto em Γ: só a banda 1 (−3,23 eV), tipo s, também espalhado. Ligação metálica: gás de elétrons quase livre.

### C, diamante (isolante)
- Valência: 8 elétrons por célula. Corte sugerido: 40 Ry.
- ecutwfc (referência 120 Ry, k 8³): 40 Ry 11,3; 50 Ry 7,3; 60 Ry 4,4; 70 Ry 1,6; 80 Ry 0,7 meV/átomo. Para 1 meV/átomo, ~80 Ry. Há um platô entre 45 e 50 Ry: quem para cedo erra.
- Malha k: centrada 6³ 4,6, 8³ 0,4, 10³ 0,04 meV/átomo; deslocada 4³ 0,2, 6³ 0,01. Converge rápido (isolante).
- a₀ (PBE) = 3,571 Å (6,748 bohr), +0,1% (exp. 3,567). B₀ ≈ 433 GPa (exp. ≈ 443).
- Gap indireto 4,15 eV: VBM em Γ, CBM a 0,73 do caminho Γ–X. Gap direto em Γ: 5,60 eV. Experimento: 5,47 eV indireto, ≈ 7,3 eV direto. O PBE subestima ~25%.
- DOS: zero no gap; DOS integrada logo acima do VBM = 8,00. Largura da valência ≈ 21,4 eV.
- Löwdin: s 0,94, p 3,05 por átomo (sp³); spilling 0,004.

- 5.6 (densidade, C): carga concentrada ao longo das ligações C–C; ao longo da ligação 0,11 (núcleo) → 0,28 (perto dos átomos) → 0,24 no centro: duas corcovas, mais marcadas que no Si (os 2p do C não têm nó de caroço). Mínimo no plano 0,013, máximo 0,286. ∫ n = 32,00. Γ, bandas 2–4 (13,27 eV, topo da valência): sobre as ligações. Covalente.

### MgO (isolante)
- Valência: 16 elétrons por célula (Mg com semicaroço 2s2p: 10; O: 6). Cortes sugeridos: Mg 58 Ry, O 47 Ry.
- ecutwfc (referência 120 Ry, k 8³): 60 Ry 33,7; 70 Ry 17,4; 80 Ry 5,6; 90 Ry 2,2; 100 Ry 1,7 meV/átomo. A energia total só chega a 1 meV/átomo acima de ~110 Ry (o semicaroço do Mg é duro). Mas a₀ = 4,2541 Å a 60 Ry e 4,2542 Å a 90 Ry: o parâmetro de rede está convergido muito antes. Bom aluno: percebe e justifica a escolha pela grandeza reportada.
- Malha k (60 Ry, referência 20³ deslocada): centradas 4³ 6,2; 6³ 0,22; 8³ 0,02 meV/átomo; deslocadas já em 4³ < 0,01. Converge rápido.
- a₀ (PBE) = 4,254 Å (8,039 bohr), +1,0% (exp. 4,212). B₀ ≈ 149 GPa (exp. ≈ 160).
- Gap direto em Γ: 4,46 eV. Em X: 10,4 eV; em L: 8,3 eV. Experimento: ≈ 7,8 eV. O PBE subestima ~43%.
- PDOS: topo da valência O 2p, base da condução Mg 3s / O 3s. DOS integrada no gap: 16,00.
- Löwdin: Mg 8,48 (s 2,48, p 6,00), O 7,35 (s 1,85, p 5,50); spilling 0,010. A carga de Löwdin não dá "Mg²⁺ / O²⁻" inteiros: é dependente da base (Aula 7).
- Custo: é o material mais caro. Um scf a 100 Ry com 8³ leva ~25 s aqui; a solução completa a 100 Ry levou 25 min (a varredura de k até 20³ sozinha, 14 min). Aceitar varreduras de k num corte menor (o notebook sugere isso) e E(a), bandas e DOS a 60–80 Ry com a justificativa de que a₀ já está convergido.

- 5.6 (densidade, MgO): em escala linear só se vê o semicaroço 2s2p do Mg (pico 7,3 elétrons/bohr³); com escala log aparecem camadas fechadas em volta de cada íon e quase nada entre eles (0,04 no meio do caminho Mg–O; ~1,0 na camada do O). ∫ n = 64,00. Γ, bandas 6–8 (topo da valência): inteiramente no O (O 2p). Iônica. Bom aluno: usa escala log (o notebook dá a dica) e mostra o perfil Mg→O.
- Tempo da solução completa a 100 Ry: 25 min (varredura de k ~14 min; etapa 5.6, 50 s).

## 4. Correção: sugestões

- 5.1: input correto (ibrav, celldm em bohr, nat/ntyp, ecutrho 8×, occupations coerentes, massas e pseudos, posições em alat). Errar Å/bohr é o erro mais comum: a₀ sai 47% fora.
- 5.2: critério explícito, gráficos em escala log, escolha justificada. Para metais, discussão da oscilação.
- 5.3: ≥ 7 pontos, ajuste, erro percentual com sinal, comparação coerente com PBE.
- 5.4–5.5: bandas e DOS em a₀; zero de energia correto; DOS integrada conferida; PDOS identificando os orbitais das bordas.
- 5.6: mapa no plano (110) com átomos e escala adequada; ∫ n conferida (4 × elétrons por célula primitiva); estado ocupado mais alto em Γ somando a degenerescência; tipo de ligação justificado pelos mapas (e comparado com o Si).
- 5.7: usa bandas e DOS; gap direto/indireto com os pontos k; comparação com o experimento com fonte; discussão do gap de KS (Q8).
- 5.8: tabela completa.
