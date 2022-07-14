﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Copium.BuildTool.Core;


public sealed class DirectoryItem
{
    private readonly DirectoryInfo m_internal;

    public string FullPath => m_internal.FullName;
    public string Name     => m_internal.Name;
    public bool   Exists   => m_internal.Exists;
    public DirectoryItem Parent
    {
        get
        {
            DirectoryInfo? parentDir = m_internal.Parent;
            if (parentDir == null)
            {
                throw new NullReferenceException($"Directory doesn't have a parent [{FullPath}]");
            }
            return new DirectoryItem(parentDir);
        }
    }


    public DirectoryItem(string dirPath)
        : this(new DirectoryInfo(dirPath))
    {
    }

    public DirectoryItem(DirectoryInfo dir)
    {
        m_internal = dir;
    }


    public void Create()               => m_internal.Create();
    public void Delete()               => m_internal.Delete();
    public void Delete(bool recursive) => m_internal.Delete(recursive);


    public IEnumerable<DirectoryItem> EnumerateDirectories()
    {
        return m_internal.EnumerateDirectories()
            .Select(dirInfo => new DirectoryItem(dirInfo));
    }

    public IEnumerable<FileItem> EnumerateFiles()
    {
        return m_internal.EnumerateFiles("*.*", SearchOption.AllDirectories)
            .Select(fileInfo => new FileItem(fileInfo));
    }

    public FileItem[] GetFiles(string searchPattern = "*.*", SearchOption searchOption = SearchOption.AllDirectories)
    {
        return Array.ConvertAll(m_internal.GetFiles(searchPattern, searchOption), file => new FileItem(file));
    }


    public FileItem MakeSubFileItem(ReadOnlySpan<char> path)
    {
        return new FileItem(Path.Join(FullPath, path));
    }

    public FileItem MakeSubFileItem(ReadOnlySpan<char> path1, ReadOnlySpan<char> path2)
    {
        return new FileItem(Path.Join(FullPath, path1, path2));
    }

    public DirectoryItem MakeSubDirItem(ReadOnlySpan<char> path)
    {
        return new DirectoryItem(Path.Join(FullPath, path));
    }

    public DirectoryItem MakeSubDirItem(ReadOnlySpan<char> path1, ReadOnlySpan<char> path2)
    {
        return new DirectoryItem(Path.Join(FullPath, path1, path2));
    }

    public DirectoryItem MakeSubDirItem(ReadOnlySpan<char> path1, ReadOnlySpan<char> path2, ReadOnlySpan<char> path3)
    {
        return new DirectoryItem(Path.Join(FullPath, path1, path2, path3));
    }
}
