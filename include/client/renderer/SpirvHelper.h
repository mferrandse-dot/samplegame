//
// Created by Mathi on 16/02/2026.
//

#ifndef SAMPLEGAME_SPIRVHELPER_H
#define SAMPLEGAME_SPIRVHELPER_H

#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>

struct SpirvHelper
{
	static void Init();

	static void Finalize();

	static void InitResources(TBuiltInResource &Resources);

	static bool GLSLtoSPV(EShLanguage stage, const char *pshader, std::vector<unsigned int> &spirv);

	static std::string GetFileText(std::string filename);
};

#endif //SAMPLEGAME_SPIRVHELPER_H