from asyncore import write
import random

c = [842767,142871,203295,871968,212512,548386,984622,977975,418875,633406,159295,542805,35930,503902,608874,868981,532088,660603,555132,402044,519809,553604,274568,596105,31890,213650,220320,533154,845987,887973,201897,443564,411820,78515,798391,967875,191689,762061,434381,526033,906966,315100,791773,37086,935648,627937,626921,2283,225007,778486,458488,833273,797434,919291,667901,121087,513282,695556,134918,44824,396569,698650,35100,632604,251171,706855,935719,408368,601396,315705,58169,859966,963915,144722,406874,955229,356707,397157,26999,935289,691579,495998,682376,826765,522127,926615,788386,863141,303529,138672,910261,330166,626617,394209,117219,268778,598509,807919,972275,184822]

a = set()



while(len(a) < 100000):
    a.add(random.randint(1, 1000000))

b = list(a)

with open("aleatorio_100k", "w") as arquivo:
    arquivo.write(f"100000\n")
    for i in range(100000):
        arquivo.write(f"{b[i]}\n")

arquivo.close()