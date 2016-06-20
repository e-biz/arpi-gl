/*
 * Copyright (C) 2015  eBusiness Information
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include "resource/ResourceManager.hpp"

#define TAG "ResourceManager"

namespace dma {

    ResourceManager::ResourceManager(const std::string& resourceDir) :
        mResourceDir(resourceDir),
        mShaderManager(mResourceDir + "shader/"),
        mMeshManager(mResourceDir + "mesh/"),
        mMapManager(mResourceDir + "texture/"),
        mCubeMapManager(mResourceDir + "texture/cubemap/"),
        mMaterialManager(mResourceDir + "material/", mShaderManager, mMapManager),
        mQuadFactory()
    {}

    ResourceManager::~ResourceManager() {
    }

    Status ResourceManager::init() {
        Log::trace(TAG, "Initializing ResourceManager...");

        mShaderManager.init();
        mMeshManager.init();
        mMapManager.init();
        mCubeMapManager.init();
        mMaterialManager.init();
        mQuadFactory.init();

        Log::trace(TAG, "ResourceManager initialized");
        return STATUS_OK;
    }

    Status ResourceManager::refresh() {
        Log::trace(TAG, "Refreshing ResourceManager...");

        if (mShaderManager.refresh() != STATUS_OK) return STATUS_KO;
        mMapManager.refresh();
        mCubeMapManager.refresh();
        if (mMeshManager.refresh() != STATUS_OK) return STATUS_KO;
        mQuadFactory.refresh();
        Log::trace(TAG, "ResourceManager refreshed");
        return STATUS_OK;
    }

    Status ResourceManager::reload() {
        Log::trace(TAG, "Reloading ResourceManager...");
        if (mShaderManager.reload() != STATUS_OK) return STATUS_KO;
        mMapManager.reload();
        mCubeMapManager.reload();
        if (mMeshManager.reload() != STATUS_OK) return STATUS_KO;
        if (mMaterialManager.reload() != STATUS_OK) return STATUS_KO;
        mQuadFactory.refresh();
        Log::trace(TAG, "ResourceManager reloaded");
        return STATUS_OK;
    }

    void ResourceManager::unload() {
        Log::trace(TAG, "Unloading ResourceManager...");
        wipe();
        mShaderManager.unload();
        mMeshManager.unload();
        mMapManager.unload();
        mCubeMapManager.unload();
        mMaterialManager.unload();
        mQuadFactory.unload();
        Log::trace(TAG, "ResourceManager unloaded");
    }

    void ResourceManager::wipe() {
        Log::trace(TAG, "Wiping ResourceManager...");
        mShaderManager.wipe();
        mMeshManager.wipe();
        mMapManager.wipe();
        mCubeMapManager.wipe();
        mQuadFactory.wipe();
        Log::trace(TAG, "ResourceManager wiped");
    }

    void ResourceManager::update() {
        Log::trace(TAG, "Updating ResourceManager...");
        mMaterialManager.update();
        mMeshManager.update();
        mMapManager.update();
        mCubeMapManager.update();
        mShaderManager.update();
        Log::trace(TAG, "ResourceManager updated");
    }
}
