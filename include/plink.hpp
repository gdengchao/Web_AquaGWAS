#pragma once

#include "assoctool.hpp"

class Plink : public AssocTool
{
public:
    Plink();

/*  !!! NOTICE:
 *
 * Any paht of binary genotype file didn't contain the suffix.
 *
*/
    // File transform
    bool vcf2transpose(string vcfFile, string out, string maf, string mind, string geno);
    bool vcf2binary(string vcfFile, string out, string maf, string mind, string geno);
    bool vcf2plink(string vcfFile, string out, string maf, string mind, string geno);
    bool plink2transpose(string pedFile, string mapFile, string out,
                         string maf, string mind, string geno);
    bool plink2binary(string pedFile, string mapFile, string out,
                      string maf, string mind, string geno);
    bool transpose2binary(string tpedFile, string tfamFile, string out,
                          string maf, string mind, string geno);
    bool transpose2plink(string tpedFile, string tfamFile, string out,
                          string maf, string mind, string geno);
    bool binary2transpose(string binaryFile, string out,
                          string maf, string mind, string geno);
    bool binary2plink(string binaryFile, string out,
                      string maf, string mind, string geno);

    // Filter data(Quality control)
    void filterVcfFile(string genotype, string maf, string mind, string geno, string out);
    void filterBinaryFile(string genotype, string maf, string mind, string geno, string out);
    void filterPlinkFile(string genotype, string map, string maf, string mind, string geno, string out);
    void filterTransposeFile(string genotype, string map, string maf, string mind, string geno, string out);
    void filterData(string genotype, string map, string maf, string mind, string geno, string out);
    void linkageFilter(string genotype, string map,
                       string winSize, string stepLen, string r2Threshold, string out);
    void extractBySnpNameFile(string genotype, string map, string snpIDFile, string outPath, string outtype);

    // Split genotype(and map) file, all of them generate map/ped file.
    void splitVcfFile(string vcfFile, string keepFile, string out, string maf, string mind, string geno);
    void splitPlinkFile(string ped, string map, string keepFile, string out, string maf, string mind, string geno);
    void splitBinaryFile(string binaryFile, string keepFile, string out, string maf, string mind, string geno);
    void splitTransposeFile(string tped, string tfam, string keepFile, string out, string maf, string mind, string geno);

    // Run
    bool runAssoc(string phenotype, string genotype, string map, string covariate, string kinship,
                 string model, string maf, string mind, string geno,string out);

private:

    bool isVcfFile(string file);
};