# nwcreate2swig

Partially SWIG-wrapper for Autodesk Navisworks NWC format (nwcreate lib). Focus on write-procedures (for create NWC-file).

Updates look at [UPDATES.md](./UPDATES.md)

## Dev

Solution `nwcreateWrapper` consists of two main projects: `nwcreateWrapperLib` and `nwcreateNET`:

* `nwcreateWrapperLib`: visual cpp project of Dynamic link library, the wrapper-classes and wrapper-enums around original Autodesk NWcreate CPP API and SWIG-interface file for wrappers. Paths to SWIG and NWcreate are stored in `.props` config file (located at `\src\nwcreateWrapperLib\nwcreateWrapperLibDeps.props`);
* `nwcreateNET`: netstandard2.0-library, all `.cs` files are cleaned as `Pre-Build`-procedure in  `nwcreateWrapperLib` and generated automatically via SWIG's command when `nwcreateWrapperLib` is compiled. The `OutDir`'s tag set to catalogue for other Vinny's tools.

## NWcreate wrapper's notes

The wrappers only created for `LcNwc*` classes and `LtNwc` enums from native Autodesk Navisworks NWcreate library. All wrapper-classes and wrapper-enums have `Wrapper` suffix. All arguments in constructors, methods are changed in wrapper-classes for more memory-efficient and protect crashes (`System.AccessViolationException`-errors).

The compulsory procedure `LiNwcApiInitialise()` is placed on `LcNwcSceneWrapper`-constructor.

ATTENTION!!!: when using `nwcreateNET`-library with other projects, which output-catalogue is different than with `nwcreateNET` wou will need to add the catalogue with `nwcreateNET.dll` to Environmental's PATH variable, otherwise you will getting an error `DllNotFoundException: Unable to load DLL 'nwcreateWrapperLib' or one of its dependencies:`

### Differences in names

* LcNwcBRepEntity::GetType() -> LcNwcBRepEntityWrapper::GetBRepEntityType() (because in .NET the `GetType()` method will conflicted with system's method);
