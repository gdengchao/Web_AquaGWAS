### 一些关于`param(map<string, string>)`的约定 [^1] 
>
|||
|  ----  | ----  |
`param["assoc"] = "1"` | // 表示要执行GWAS，值为工具类型; GWAS_TYPE_PLINK = 1; GWAS_TYPE_GEMMA = 2; GWAS_TYPE_EMMAX = 4;
`param["pca"] = "1"`    | // 表示要执行PCA分析，值为工具类型  
`param["ld"] = "1"`    |// 表示要执行LD分析，值为工具类型
`param["anno"] = "1"`    |// 表示要执行Annotation，值为Annotation类型  
`param["corr"] = "1"`    |// 表示要执行Correction，值为Correction类型  
`param["genotype"] = "path/genotype.ped"`    |// Genotype文件，带后缀用于区分文件类型  
`param["phenotype"] = "path/phenotype.phe"`    |// Phenotype文件，带后缀用于区分文件类型  
`param["out"] = "path/out/name"`           |// 输出路径，带文件前缀名  
`param["covar"] = "path/file.covar"`|// 协变量文件 
`param["kin"] = "path/file.kin"`|// 亲缘关系矩阵 
`param["out"] = "path/out/name"`|// 输出路径，带文件前缀名  
`param["geno"] = "0.05"`|// QC 参数 geno   
`param["mind"] = "0.2"`|// QC 参数 mind   
`param["maf"] = "0.05"`|// QC 参数 maf  
`param["ld_win"] = "100"`|// QC 参数 ld windows size   
`param["ld_step"] = "5"`|// QC 参数 ld step length
`param["ld_r2"] = "0.5"`|// QC 参数 ld r2 
`param["model"] = "linear"`|// GWAS模型选择
`param["gemma_complfam"] = "linear"`|// Gemma：是否先补全fam文件的phe值
`param["gemma_mat"] = "1"`|// Gemma: matrix类型
`param["gemma_bslmm"] = "1"`|// Gemma：bslmm模型类型
`param["gemma_lmm"] = "1"`|// Gemma：lmm校正类型

[^1]:作为下标的参数以及作为选择的参数值已在conf.hpp定义为常量