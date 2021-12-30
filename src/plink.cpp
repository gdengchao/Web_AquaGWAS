#include "plink.hpp"
#include "util.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

Plink::Plink()
{
    _model.push_back("Linear");
    _model.push_back("Logistic");
    _paramlist.clear();
}

bool Plink::vcf2plink(string vcfFile, string out, string maf, string mind, string geno)
{
    if (vcfFile.empty() || out.empty())
    {
        return false;
    }

    //plink --vcf vcfFile [--maf maf] [--mind mind] [--geno geno] --recode --out out

    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--vcf");
    _paramlist.push_back(vcfFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
//    _paramlist.push_back("--const-fid");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    //_paramlist.push_back("--noweb");

    return true;
}


bool Plink::vcf2binary(string vcfFile, string out, string maf, string mind, string geno)
{
    if (vcfFile.empty() || out.empty())
    {
        return false;
    }

    // plink --vcf vcfFile [--maf maf] [--mind mind] [--geno geno] --make-bed --out out
    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--vcf");
    _paramlist.push_back(vcfFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
//    _paramlist.push_back("--const-fid");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--make-bed");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

bool Plink::vcf2transpose(string vcfFile, string out, string maf, string mind, string geno)
{
    if (vcfFile.empty() || out.empty())
    {
        return false;
    }

    // plink --vcf [--maf maf] [--mind mind] [--geno geno] --recode12 --ouput-missing-genotype 0 --transpose --out out
    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--vcf");
    _paramlist.push_back(vcfFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
//    _paramlist.push_back("--const-fid");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("12");
    _paramlist.push_back("transpose");
    _paramlist.push_back("--output-missing-genotype");
    _paramlist.push_back("0");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

bool Plink::plink2transpose(string pedFile, string mapFile, string out, string maf, string mind, string geno)
{
    if (pedFile.empty() || mapFile.empty() || out.empty())
    {
        return false;
    }

    // plink --ped pedFile --map mapFile [--maf maf] [--mind mind] [--geno geno] --recode12 --transpose --out out
    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--ped");
    _paramlist.push_back(pedFile);
    _paramlist.push_back("--map");
    _paramlist.push_back(mapFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }

    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("12");
    _paramlist.push_back("transpose");
    _paramlist.push_back("--output-missing-genotype");
    _paramlist.push_back("0");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

bool Plink::plink2binary(string pedFile, string mapFile, string out, string maf, string mind, string geno)
{
    if (pedFile.empty() || mapFile.empty() || out.empty())
    {
        return false;
    }

    // plink --ped .ped --map .map [--maf maf] [--mind mind] [--geno geno] --make-bed --out out
    _paramlist.clear();
    _paramlist.push_back("--ped");
    _paramlist.push_back(pedFile);
    _paramlist.push_back("--map");
    _paramlist.push_back(mapFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--make-bed");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    //_paramlist.push_back("--noweb");

    return true;
}

bool Plink::transpose2binary(string tpedFile, string tfamFile, string out, string maf, string mind, string geno)
{
    if (tpedFile.empty() || tfamFile.empty() || out.empty())
    {
        return false;
    }

    // plink --tped .tped --tfam .tfam [--maf maf] [--mind mind] [--geno geno] --make-bed --out out
    _paramlist.clear();
    _paramlist.push_back("--tped");
    _paramlist.push_back(tpedFile);
    _paramlist.push_back("--tfam");
    _paramlist.push_back(tfamFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--make-bed");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    //_paramlist.push_back("--noweb");

    return true;
}

bool Plink::transpose2plink(string tpedFile, string tfamFile, string out, string maf, string mind, string geno)
{
    if (tpedFile.empty() || tfamFile.empty() || out.empty())
    {
        return false;
    }

    // plink --tped .tped --tfam .tfam [--maf maf] [--mind mind] [--geno geno] --recode --out out
    _paramlist.clear();
    _paramlist.push_back("--tped");
    _paramlist.push_back(tpedFile);
    _paramlist.push_back("--tfam");
    _paramlist.push_back(tfamFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

bool Plink::binary2transpose(string binaryFile, string out, string maf, string mind, string geno)
{
    if (binaryFile.empty() || out.empty())
    {
        return false;
    }

    string bedFile(binaryFile+".bed");
    string bimFile(binaryFile+".bim");
    string famFile(binaryFile+".fam");

    if (!isExist(bedFile) || !isExist(bimFile) || !isExist(famFile))
    {
        return false;
    }

    // plink --bfile binaryFile [--maf maf] [--geno ms] --recode12 --transpose --out out
    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--bfile");
    _paramlist.push_back(binaryFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("12");
    _paramlist.push_back("transpose");
    _paramlist.push_back("--output-missing-genotype");
    _paramlist.push_back("0");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

bool Plink::binary2plink(string binaryFile, string out, string maf, string mind, string geno)
{
    if (binaryFile.empty() || out.empty())
    {
        return false;
    }

    string bedFile(binaryFile+".bed");
    string bimFile(binaryFile+".bim");
    string famFile(binaryFile+".fam");

    if (!isExist(bedFile) || !isExist(bimFile) || !isExist(famFile))
    {
        return false;
    }

    // plink --bfile binaryFile [--maf maf] [--geno ms] --recode --out out
    _paramlist.clear();            // Clear paramlist before set parameter.
    _paramlist.push_back("--bfile");
    _paramlist.push_back(binaryFile);
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

void Plink::linkageFilter(string genotype, string mapfile,
                          string winSize, string stepLen, string r2Threshold, string out)
{
    // size_t len = max(genotype.size(), (size_t)256);      
        
    string genoFileName;     
    string genoFileBaseName;     
    string genoFileSuffix;         
    string genoFileAbPath;

    splitPath(genotype, genoFileAbPath, genoFileName, genoFileBaseName, genoFileSuffix);

    _paramlist.clear();            // Clear paramlist before set parameter.
    if (isVcfFile(genotype)) // Transform "vcf" to "transpose"
    {
//        _paramlist.push_back("--const-fid");
        _paramlist.push_back("--vcf");
        _paramlist.push_back(genotype);
    }
    if (genoFileSuffix == "ped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath + "/"+genoFileBaseName + ".map";
        }
        _paramlist.push_back("--ped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--map");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "tped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath+"/"+genoFileBaseName+".tfam";
        }
        _paramlist.push_back("--tped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--tfam");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "bed")
    {
        _paramlist.push_back("--bfile");
        _paramlist.push_back(genoFileAbPath+"/"+genoFileBaseName);
    }

    // plink1.9 --file 222_filter1 --allow-extra-chr --indep-pairwise 100 5 0.5 --out ldfl
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    _paramlist.push_back("--indep-pairwise");
    _paramlist.push_back(winSize);
    _paramlist.push_back(stepLen);
    _paramlist.push_back(r2Threshold);
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
}

void Plink::extractBySnpNameFile(string genotype, string mapfile, string snpIDFile, string outPath, string outType)
{
    // Genotype file info.
    string genoFileName;     
    string genoFileBaseName;     
    string genoFileSuffix;         
    string genoFileAbPath;

    splitPath(genotype, genoFileAbPath, genoFileName, genoFileBaseName, genoFileSuffix);

    _paramlist.clear();            // Clear paramlist before set parameter.
    if (isVcfFile(genotype)) // Transform "vcf" to "transpose"
    {
//        _paramlist.push_back("--const-fid");
        _paramlist.push_back("--vcf");
        _paramlist.push_back(genotype);
    }
    if (genoFileSuffix == "ped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath+"/"+genoFileBaseName+".map";
        }
        _paramlist.push_back("--ped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--map");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "tped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath+"/"+genoFileBaseName+".tfam";
        }
        _paramlist.push_back("--tped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--tfam");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "bed")
    {
        _paramlist.push_back("--bfile");
        _paramlist.push_back(genoFileAbPath+"/"+genoFileBaseName);
    }

    // plink1.9 --file 222_filter1 --allow-extra-chr --extract ldfl.prune.in --recode --out 222_filter1_ldfl
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    _paramlist.push_back("--extract");
    _paramlist.push_back(snpIDFile);

    if (outType == "binary")
    {
        _paramlist.push_back("--make-bed");
    }
    else if (outType == "plink")
    {
        _paramlist.push_back("--recode");
    }
    else if (outType == "transpose")
    {
        _paramlist.push_back("--recode");
        _paramlist.push_back("12");
        _paramlist.push_back("transpose");
        _paramlist.push_back("--output-missing-genotype");
        _paramlist.push_back("0");
    }
    else if (outType == "vcf")
    {
        _paramlist.push_back("--recode");
        _paramlist.push_back("vcf");
    }
    _paramlist.push_back("--out");
    _paramlist.push_back(outPath);
}

bool Plink::runAssoc(string phenotype, string genotype, string mapfile, string covariate, string kinship,
                    string model, string maf, string mind, string geno,string out)
{
    if (phenotype.empty() || genotype.empty() || model.empty())
    {
        return false;
    }

    // Genotype file info.
    string genoFileName;     
    string genoFileBaseName;     
    string genoFileSuffix;         
    string genoFileAbPath;

    splitPath(genotype, genoFileAbPath, genoFileName, genoFileBaseName, genoFileSuffix);

    _paramlist.clear();            // Clear paramlist before set parameter.
    if (isVcfFile(genotype)) // Transform "vcf" to "transpose"
    {
//        _paramlist.push_back("--const-fid");
        _paramlist.push_back("--vcf");
        _paramlist.push_back(genotype);
    }
    if (genoFileSuffix == "ped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath+"/"+genoFileBaseName+".map";
        }
        _paramlist.push_back("--ped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--map");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "tped")
    {
        if (mapfile.empty())
        {
            mapfile = genoFileAbPath+"/"+genoFileBaseName+".tfam";
        }
        _paramlist.push_back("--tped");
        _paramlist.push_back(genotype);
        _paramlist.push_back("--tfam");
        _paramlist.push_back(mapfile);
    }

    if (genoFileSuffix == "bed")
    {
        _paramlist.push_back("--bfile");
        _paramlist.push_back(genoFileAbPath+"/"+genoFileBaseName);
    }

    _paramlist.push_back("--pheno");
    _paramlist.push_back(phenotype);

    if (!covariate.empty())
    {
        _paramlist.push_back("--covar");
        _paramlist.push_back(covariate);
    }
    if (!kinship.empty())
    {   //

    }

    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
    }

    if (model == "Linear" || model == "linear")
    {
        _paramlist.push_back("--linear");
    }
    if (model == "Logistic" || model == "logistic")
    {
        _paramlist.push_back("--logistic");
    }
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--allow-no-sex");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);

    return true;
}

void Plink::filterVcfFile(string genotype, string maf, string mind, string geno, string out)
{
    _paramlist.clear();
    _paramlist.push_back("--vcf");
    _paramlist.push_back(genotype);

    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--recode");
    _paramlist.push_back("vcf");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
}

void Plink::filterPlinkFile(string genotype, string mapfile, string maf, string mind, string geno, string out)
{
    _paramlist.clear();
    _paramlist.push_back("--ped");
    _paramlist.push_back(genotype);
    _paramlist.push_back("--map");
    _paramlist.push_back(mapfile);

    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
    _paramlist.push_back("--allow-extra-chr");
    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
}

void Plink::filterBinaryFile(string genotype, string maf, string mind, string geno, string out)
{
    _paramlist.clear();
    _paramlist.push_back("--bfile");
    _paramlist.push_back(genotype);
    _paramlist.push_back("--allow-extra-chr");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--make-bed");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
}

void Plink::filterTransposeFile(string genotype, string mapfile, string maf, string mind, string geno, string out)
{
    _paramlist.clear();
    _paramlist.push_back("--tped");
    _paramlist.push_back(genotype);
    _paramlist.push_back("--tfam");
    _paramlist.push_back(mapfile);
    _paramlist.push_back("--allow-extra-chr");
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }

    _paramlist.push_back("--recode");
    _paramlist.push_back("12");
    _paramlist.push_back("transpose");
    _paramlist.push_back("--output-missing-genotype");
    _paramlist.push_back("0");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
}

/**
 * @brief Plink::filterData
 * @param genotype
 * @param map
 * @param maf
 * @param mind
 * @param geno
 * @param out       Transpose file
 */
void Plink::filterData(string genotype, string mapfile, string maf, string mind, string geno, string out)
{
    if (genotype.empty() || mapfile.empty())
    {
        return;
    }

    string genoFileName;     
    string genoFileBaseName;     
    string genoFileSuffix;         
    string genoFileAbPath;

    splitPath(genotype, genoFileAbPath, genoFileName, genoFileBaseName, genoFileSuffix);

    if (isVcfFile(genotype))
    {
        filterVcfFile(genotype, maf, mind, geno, out);
    }

    if (genoFileSuffix == "ped")
    {
        filterPlinkFile(genotype, mapfile, maf, mind, geno, out);
    }

    if (genoFileSuffix == "tped")
    {
        filterTransposeFile(genotype, mapfile, maf, mind, geno, out);
    }

    if (genoFileSuffix == "bed")
    {
        filterBinaryFile(genoFileAbPath+"/"+genoFileBaseName, maf, mind, geno, out);
        _paramlist.push_back("--output-missing-genotype");
        _paramlist.push_back("0");
        _paramlist.push_back("--recode");
        _paramlist.push_back("12");
        _paramlist.push_back("transpose");
        _paramlist.push_back("--out");
        _paramlist.push_back(out);
    }
}

bool Plink::isVcfFile(string file) // Just consider filename.
{
    if (file.empty() || file.empty())
    {
        return false;
    }

    string fileName;     
    string fileBaseName;     
    string fileSuffix;         
    string fileAbPath;

    splitPath(file, fileAbPath, fileName, fileBaseName, fileSuffix);
    list<string> fileNameList = split(fileName, ".");         // demo.vcf.gz

    for (string item : fileNameList)
    {
        if (item == "vcf")
        {
            return true;
        }
    }

    return false;
}

void Plink::splitVcfFile(string vcfFile, string keepFile, string out, string maf, string mind, string geno)
{
    if (vcfFile.empty() ||  keepFile.empty())
    {
        return;
    }
    _paramlist.clear();
    _paramlist.push_back("--vcf");
    _paramlist.push_back(vcfFile);
    _paramlist.push_back("--keep");
    _paramlist.push_back(keepFile);
    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
}

void Plink::splitPlinkFile(string ped, string mapfile, string keepFile, string out, string maf, string mind, string geno)
{
    if (ped.empty() || mapfile.empty() ||  keepFile.empty())
    {
        return;
    }
    _paramlist.clear();
    _paramlist.push_back("--ped");
    _paramlist.push_back(ped);
    _paramlist.push_back("--map");
    _paramlist.push_back(mapfile);
    _paramlist.push_back("--keep");
    _paramlist.push_back(keepFile);
    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
}

void Plink::splitBinaryFile(string binaryFile, string keepFile, string out, string maf, string mind, string geno)
{
    if (binaryFile.empty() ||  keepFile.empty())
    {
        return;
    }
    if (!isExist(binaryFile+".bed") || !isExist(binaryFile+".bim") || !isExist(binaryFile+".fam"))
    {
        return;
    }

    _paramlist.clear();
    _paramlist.push_back("--bfile");
    _paramlist.push_back(binaryFile);
    _paramlist.push_back("--keep");
    _paramlist.push_back(keepFile);
    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
}

void Plink::splitTransposeFile(string tped, string tfam, string keepFile, string out, string maf, string mind, string geno)
{
    if (tped.empty() || tfam.empty() ||  keepFile.empty())
    {
        return;
    }
    _paramlist.clear();
    _paramlist.push_back("--tped");
    _paramlist.push_back(tped);
    _paramlist.push_back("--tfam");
    _paramlist.push_back(tfam);
    _paramlist.push_back("--keep");
    _paramlist.push_back(keepFile);
    _paramlist.push_back("--recode");
    _paramlist.push_back("--out");
    _paramlist.push_back(out);
    if (!maf.empty())
    {
        _paramlist.push_back("--maf");
        _paramlist.push_back(maf);
    }
    if (!mind.empty())
    {
        _paramlist.push_back("--mind");
        _paramlist.push_back(mind);
    }
    if (!geno.empty())
    {
        _paramlist.push_back("--geno");
        _paramlist.push_back(geno);
    }
}