/*
 *
 * Copyright (C) 2020 Intel Corporation
 *
 * Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
 * See LICENSE.TXT
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 * @file ur_api.cpp
 * @version v0.11-r0
 *
 */
#include "ur_api.h"

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a loader config object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phLoaderConfig`
ur_result_t UR_APICALL urLoaderConfigCreate(
    ur_loader_config_handle_t *
        phLoaderConfig ///< [out] Pointer to handle of loader config object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the loader config object.
///
/// @details
///     - Get a reference to the loader config handle. Increment its reference
///       count
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
ur_result_t UR_APICALL urLoaderConfigRetain(
    ur_loader_config_handle_t
        hLoaderConfig ///< [in][retain] loader config handle to retain
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release config handle.
///
/// @details
///     - Decrement reference count and destroy the config handle if reference
///       count becomes zero.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
ur_result_t UR_APICALL urLoaderConfigRelease(
    ur_loader_config_handle_t
        hLoaderConfig ///< [in][release] config handle to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves various information about the loader.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_LOADER_CONFIG_INFO_REFERENCE_COUNT < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the loader.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urLoaderConfigGetInfo(
    ur_loader_config_handle_t
        hLoaderConfig, ///< [in] handle of the loader config object
    ur_loader_config_info_t propName, ///< [in] type of the info to retrieve
    size_t propSize, ///< [in] the number of bytes pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return the info
    ///< then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enable a layer for the specified loader config.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pLayerName`
///     - ::UR_RESULT_ERROR_LAYER_NOT_PRESENT
///         + If layer specified with `pLayerName` can't be found by the loader.
ur_result_t UR_APICALL urLoaderConfigEnableLayer(
    ur_loader_config_handle_t
        hLoaderConfig, ///< [in] Handle to config object the layer will be enabled for.
    const char *
        pLayerName ///< [in] Null terminated string containing the name of the layer to
                   ///< enable. Empty if none are enabled.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set a function callback for use by the loader to retrieve code
///        location information.
///
/// @details
///     - The code location callback is optional and provides additional
///       information to the tracing layer about the entry point of the current
///       execution flow.
///     - This functionality can be used to match traced unified runtime
///       function calls with higher-level user calls.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pfnCodeloc`
ur_result_t UR_APICALL urLoaderConfigSetCodeLocationCallback(
    ur_loader_config_handle_t
        hLoaderConfig, ///< [in] Handle to config object the layer will be enabled for.
    ur_code_location_callback_t
        pfnCodeloc, ///< [in] Function pointer to code location callback.
    void *
        pUserData ///< [in][out][optional] pointer to data to be passed to callback.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief The only adapter reported with mock enabled will be the mock adapter.
///
/// @details
///     - The mock adapter will default to returning ::UR_RESULT_SUCCESS for all
///       entry points. It will also create and correctly reference count dummy
///       handles where appropriate. Its behaviour can be modified by linking
///       the mock library and using the object accessed via
///       mock::getCallbacks().
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hLoaderConfig`
ur_result_t UR_APICALL urLoaderConfigSetMockingEnabled(
    ur_loader_config_handle_t
        hLoaderConfig, ///< [in] Handle to config object mocking will be enabled for.
    ur_bool_t
        enable ///< [in] Handle to config object the layer will be enabled for.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Initialize the 'oneAPI' loader
///
/// @details
///     - The application must call this function before calling any other
///       function.
///     - If this function is not called then all other functions will return
///       ::UR_RESULT_ERROR_UNINITIALIZED.
///     - Only one instance of the loader will be initialized per process.
///     - The application may call this function multiple times with different
///       flags or environment variables enabled.
///     - The application must call this function after forking new processes.
///       Each forked process must call this function.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function must be thread-safe for scenarios
///       where multiple libraries may initialize the loader simultaneously.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_DEVICE_INIT_FLAGS_MASK & device_flags`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urLoaderInit(
    ur_device_init_flags_t device_flags, ///< [in] device initialization flags.
    ///< must be 0 (default) or a combination of ::ur_device_init_flag_t.
    ur_loader_config_handle_t
        hLoaderConfig ///< [in][optional] Handle of loader config handle.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Tear down the 'oneAPI' loader and release all its resources
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urLoaderTearDown(void) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves all available adapters
///
/// @details
///     - Adapter implementations must return exactly one adapter handle from
///       this entry point.
///     - The loader may return more than one adapter handle when there are
///       multiple available.
///     - Each returned adapter has its reference count incremented and should
///       be released with a subsequent call to ::urAdapterRelease.
///     - Adapters may perform adapter-specific state initialization when the
///       first reference to them is taken.
///     - An application may call this entry point multiple times to acquire
///       multiple references to the adapter handle(s).
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NumEntries == 0 && phAdapters != NULL`
ur_result_t UR_APICALL urAdapterGet(
    uint32_t
        NumEntries, ///< [in] the number of adapters to be added to phAdapters.
    ///< If phAdapters is not NULL, then NumEntries should be greater than
    ///< zero, otherwise ::UR_RESULT_ERROR_INVALID_SIZE,
    ///< will be returned.
    ur_adapter_handle_t *
        phAdapters, ///< [out][optional][range(0, NumEntries)] array of handle of adapters.
    ///< If NumEntries is less than the number of adapters available, then
    ///< ::urAdapterGet shall only retrieve that number of adapters.
    uint32_t *
        pNumAdapters ///< [out][optional] returns the total number of adapters available.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Releases the adapter handle reference indicating end of its usage
///
/// @details
///     - When the reference count of the adapter reaches zero, the adapter may
///       perform adapter-specififc resource teardown. Resources must be left in
///       a state where it safe for the adapter to be subsequently reinitialized
///       with ::urAdapterGet
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
ur_result_t UR_APICALL urAdapterRelease(
    ur_adapter_handle_t hAdapter ///< [in][release] Adapter handle to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the adapter handle.
///
/// @details
///     - Get a reference to the adapter handle. Increment its reference count
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
ur_result_t UR_APICALL urAdapterRetain(
    ur_adapter_handle_t hAdapter ///< [in][retain] Adapter handle to retain
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the last adapter specific error.
///
/// @details
/// To be used after another entry-point has returned
/// ::UR_RESULT_ERROR_ADAPTER_SPECIFIC in order to retrieve a message describing
/// the circumstances of the underlying driver error and the error code
/// returned by the failed driver entry-point.
///
/// * Implementations *must* store the message and error code in thread-local
///   storage prior to returning ::UR_RESULT_ERROR_ADAPTER_SPECIFIC.
///
/// * The message and error code storage is will only be valid if a previously
///   called entry-point returned ::UR_RESULT_ERROR_ADAPTER_SPECIFIC.
///
/// * The memory pointed to by the C string returned in `ppMessage` is owned by
///   the adapter and *must* be null terminated.
///
/// * The application *may* call this function from simultaneous threads.
///
/// * The implementation of this function *should* be lock-free.
///
/// Example usage:
///
/// ```cpp
/// if (::urQueueCreate(hContext, hDevice, nullptr, &hQueue) ==
///         ::UR_RESULT_ERROR_ADAPTER_SPECIFIC) {
///     const char* pMessage;
///     int32_t error;
///     ::urAdapterGetLastError(hAdapter, &pMessage, &error);
/// }
/// ```
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppMessage`
///         + `NULL == pError`
ur_result_t UR_APICALL urAdapterGetLastError(
    ur_adapter_handle_t hAdapter, ///< [in] handle of the adapter instance
    const char **
        ppMessage, ///< [out] pointer to a C string where the adapter specific error message
                   ///< will be stored.
    int32_t *
        pError ///< [out] pointer to an integer where the adapter specific error code will
               ///< be stored.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves information about the adapter
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_ADAPTER_INFO_VERSION < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urAdapterGetInfo(
    ur_adapter_handle_t hAdapter, ///< [in] handle of the adapter
    ur_adapter_info_t propName,   ///< [in] type of the info to retrieve
    size_t propSize, ///< [in] the number of bytes pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If Size is not equal to or greater to the real number of bytes needed
    ///< to return the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is
    ///< returned and pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual number of bytes being queried by pPropValue.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves all available platforms for the given adapters
///
/// @details
///     - Multiple calls to this function will return identical platforms
///       handles, in the same order.
///     - The application may call this function from simultaneous threads, the
///       implementation must be thread-safe
///
/// @remarks
///   _Analogues_
///     - **clGetPlatformIDs**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phAdapters`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NumEntries == 0 && phPlatforms != NULL`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pNumPlatforms == NULL && phPlatforms == NULL`
ur_result_t UR_APICALL urPlatformGet(
    ur_adapter_handle_t *
        phAdapters, ///< [in][range(0, NumAdapters)] array of adapters to query for platforms.
    uint32_t NumAdapters, ///< [in] number of adapters pointed to by phAdapters
    uint32_t
        NumEntries, ///< [in] the number of platforms to be added to phPlatforms.
    ///< If phPlatforms is not NULL, then NumEntries should be greater than
    ///< zero, otherwise ::UR_RESULT_ERROR_INVALID_SIZE,
    ///< will be returned.
    ur_platform_handle_t *
        phPlatforms, ///< [out][optional][range(0, NumEntries)] array of handle of platforms.
    ///< If NumEntries is less than the number of platforms available, then
    ///< ::urPlatformGet shall only retrieve that number of platforms.
    uint32_t *
        pNumPlatforms ///< [out][optional] returns the total number of platforms available.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves various information about platform
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clGetPlatformInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_PLATFORM_INFO_BACKEND < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_PLATFORM
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urPlatformGetInfo(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform
    ur_platform_info_t propName,    ///< [in] type of the info to retrieve
    size_t propSize, ///< [in] the number of bytes pointed to by pPlatformInfo.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If Size is not equal to or greater to the real number of bytes needed
    ///< to return the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is
    ///< returned and pPlatformInfo is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual number of bytes being queried by pPlatformInfo.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns the API version supported by the specified platform
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pVersion`
ur_result_t UR_APICALL urPlatformGetApiVersion(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform
    ur_api_version_t *pVersion      ///< [out] api version
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native platform handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativePlatform`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urPlatformGetNativeHandle(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform.
    ur_native_handle_t *
        phNativePlatform ///< [out] a pointer to the native handle of the platform.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime platform object from native platform handle.
///
/// @details
///     - Creates runtime platform handle from native driver platform handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phPlatform`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urPlatformCreateWithNativeHandle(
    ur_native_handle_t
        hNativePlatform, ///< [in][nocheck] the native handle of the platform.
    ur_adapter_handle_t
        hAdapter, ///< [in] handle of the adapter associated with the native backend.
    const ur_platform_native_properties_t *
        pProperties, ///< [in][optional] pointer to native platform properties struct.
    ur_platform_handle_t *
        phPlatform ///< [out] pointer to the handle of the platform object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the platform specific compiler backend option from a generic
///        frontend option.
///
/// @details
///     - The string returned via the ppPlatformOption is a NULL terminated C
///       style string.
///     - The string returned via the ppPlatformOption is thread local.
///     - The memory in the string returned via the ppPlatformOption is owned by
///       the adapter.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pFrontendOption`
///         + `NULL == ppPlatformOption`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + If `pFrontendOption` is not a valid frontend option.
ur_result_t UR_APICALL urPlatformGetBackendOption(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform instance.
    const char
        *pFrontendOption, ///< [in] string containing the frontend option.
    const char **
        ppPlatformOption ///< [out] returns the correct platform specific compiler option based on
                         ///< the frontend option.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves devices within a platform
///
/// @details
///     - Multiple calls to this function will return identical device handles,
///       in the same order.
///     - The number and order of handles returned from this function can be
///       affected by environment variables that filter devices exposed through
///       API.
///     - The returned devices are taken a reference of and must be released
///       with a subsequent call to ::urDeviceRelease.
///     - The application may call this function from simultaneous threads, the
///       implementation must be thread-safe
///
/// @remarks
///   _Analogues_
///     - **clGetDeviceIDs**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_DEVICE_TYPE_VPU < DeviceType`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NumEntries == 0 && phDevices != NULL`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NumEntries > 0 && phDevices == NULL`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urDeviceGet(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform instance
    ur_device_type_t DeviceType,    ///< [in] the type of the devices.
    uint32_t
        NumEntries, ///< [in] the number of devices to be added to phDevices.
    ///< If phDevices is not NULL, then NumEntries should be greater than zero.
    ///< Otherwise ::UR_RESULT_ERROR_INVALID_SIZE
    ///< will be returned.
    ur_device_handle_t *
        phDevices, ///< [out][optional][range(0, NumEntries)] array of handle of devices.
    ///< If NumEntries is less than the number of devices available, then
    ///< platform shall only retrieve that number of devices.
    uint32_t *pNumDevices ///< [out][optional] pointer to the number of devices.
    ///< pNumDevices will be updated with the total number of devices available.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves devices within a platform selected by ONEAPI_DEVICE_SELECTOR
///
/// @details
///     - Multiple calls to this function will return identical device handles,
///       in the same order.
///     - The number and order of handles returned from this function will be
///       affected by environment variables that filter or select which devices
///       are exposed through this API.
///     - A reference is taken for each returned device and must be released
///       with a subsequent call to ::urDeviceRelease.
///     - The application may call this function from simultaneous threads, the
///       implementation must be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPlatform`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_DEVICE_TYPE_VPU < DeviceType`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urDeviceGetSelected(
    ur_platform_handle_t hPlatform, ///< [in] handle of the platform instance
    ur_device_type_t DeviceType,    ///< [in] the type of the devices.
    uint32_t
        NumEntries, ///< [in] the number of devices to be added to phDevices.
    ///< If phDevices in not NULL then NumEntries should be greater than zero,
    ///< otherwise ::UR_RESULT_ERROR_INVALID_VALUE,
    ///< will be returned.
    ur_device_handle_t *
        phDevices, ///< [out][optional][range(0, NumEntries)] array of handle of devices.
    ///< If NumEntries is less than the number of devices available, then only
    ///< that number of devices will be retrieved.
    uint32_t *pNumDevices ///< [out][optional] pointer to the number of devices.
    ///< pNumDevices will be updated with the total number of selected devices
    ///< available for the given platform.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves various information about device
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clGetDeviceInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_DEVICE_INFO_2D_BLOCK_ARRAY_CAPABILITIES_EXP < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urDeviceGetInfo(
    ur_device_handle_t hDevice, ///< [in] handle of the device instance
    ur_device_info_t propName,  ///< [in] type of the info to retrieve
    size_t propSize, ///< [in] the number of bytes pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return the info
    ///< then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Makes a reference of the device handle indicating it's in use until
///        paired ::urDeviceRelease is called
///
/// @details
///     - Increments the device reference count if `hDevice` is a valid
///       sub-device created by a call to `urDevicePartition`. If `hDevice` is a
///       root level device (e.g. obtained with `urDeviceGet`), the reference
///       count remains unchanged.
///     - It is not valid to use the device handle, which has all of its
///       references released.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clRetainDevice**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
ur_result_t UR_APICALL urDeviceRetain(
    ur_device_handle_t
        hDevice ///< [in][retain] handle of the device to get a reference of.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Releases the device handle reference indicating end of its usage
///
/// @details
///     - Decrements the device reference count if `hDevice` is a valid
///       sub-device created by a call to `urDevicePartition`. If `hDevice` is a
///       root level device (e.g. obtained with `urDeviceGet`), the reference
///       count remains unchanged.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clReleaseDevice**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
ur_result_t UR_APICALL urDeviceRelease(
    ur_device_handle_t
        hDevice ///< [in][release] handle of the device to release.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Partition the device into sub-devices
///
/// @details
///     - Repeated calls to this function with the same inputs will produce the
///       same output in the same order.
///     - The function may be called to request a further partitioning of a
///       sub-device into sub-sub-devices, and so on.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clCreateSubDevices**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pProperties`
///         + `NULL == pProperties->pProperties`
///     - ::UR_RESULT_ERROR_DEVICE_PARTITION_FAILED
///     - ::UR_RESULT_ERROR_INVALID_DEVICE_PARTITION_COUNT
ur_result_t UR_APICALL urDevicePartition(
    ur_device_handle_t hDevice, ///< [in] handle of the device to partition.
    const ur_device_partition_properties_t
        *pProperties,    ///< [in] Device partition properties.
    uint32_t NumDevices, ///< [in] the number of sub-devices.
    ur_device_handle_t *
        phSubDevices, ///< [out][optional][range(0, NumDevices)] array of handle of devices.
    ///< If NumDevices is less than the number of sub-devices available, then
    ///< the function shall only retrieve that number of sub-devices.
    uint32_t *
        pNumDevicesRet ///< [out][optional] pointer to the number of sub-devices the device can be
    ///< partitioned into according to the partitioning property.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Selects the most appropriate device binary based on runtime
///        information and the IR characteristics.
///
/// @details
///     - The input binaries are various AOT images, and possibly an IL binary
///       for JIT compilation.
///     - The selected binary will be able to be run on the target device.
///     - If no suitable binary can be found then function returns
///       ${X}_INVALID_BINARY.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pBinaries`
///         + `NULL == pSelectedBinary`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NumBinaries == 0`
ur_result_t UR_APICALL urDeviceSelectBinary(
    ur_device_handle_t
        hDevice, ///< [in] handle of the device to select binary for.
    const ur_device_binary_t
        *pBinaries,       ///< [in] the array of binaries to select from.
    uint32_t NumBinaries, ///< [in] the number of binaries passed in ppBinaries.
                          ///< Must greater than or equal to zero otherwise
                          ///< ::UR_RESULT_ERROR_INVALID_VALUE is returned.
    uint32_t *
        pSelectedBinary ///< [out] the index of the selected binary in the input array of binaries.
    ///< If a suitable binary was not found the function returns ::UR_RESULT_ERROR_INVALID_BINARY.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native device handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeDevice`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urDeviceGetNativeHandle(
    ur_device_handle_t hDevice, ///< [in] handle of the device.
    ur_native_handle_t
        *phNativeDevice ///< [out] a pointer to the native handle of the device.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime device object from native device handle.
///
/// @details
///     - Creates runtime device handle from native driver device handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevice`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urDeviceCreateWithNativeHandle(
    ur_native_handle_t
        hNativeDevice, ///< [in][nocheck] the native handle of the device.
    ur_adapter_handle_t
        hAdapter, ///< [in] handle of the adapter to which `hNativeDevice` belongs
    const ur_device_native_properties_t *
        pProperties, ///< [in][optional] pointer to native device properties struct.
    ur_device_handle_t
        *phDevice ///< [out] pointer to the handle of the device object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns synchronized Host and Device global timestamps.
///
/// @details
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clGetDeviceAndHostTimer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
ur_result_t UR_APICALL urDeviceGetGlobalTimestamps(
    ur_device_handle_t hDevice, ///< [in] handle of the device instance
    uint64_t *
        pDeviceTimestamp, ///< [out][optional] pointer to the Device's global timestamp that
                          ///< correlates with the Host's global timestamp value
    uint64_t *
        pHostTimestamp ///< [out][optional] pointer to the Host's global timestamp that
                       ///< correlates with the Device's global timestamp value
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates a context with the given devices.
///
/// @details
///     - All devices should be from the same platform.
///     - Context is used for resource sharing between all the devices
///       associated with it.
///     - Context also serves for resource isolation such that resources do not
///       cross context boundaries.
///     - The returned context is a reference and must be released with a
///       subsequent call to ::urContextRelease.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function must be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clCreateContext**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevices`
///         + `NULL == phContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_CONTEXT_FLAGS_MASK & pProperties->flags`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ur_result_t UR_APICALL urContextCreate(
    uint32_t DeviceCount, ///< [in] the number of devices given in phDevices
    const ur_device_handle_t
        *phDevices, ///< [in][range(0, DeviceCount)] array of handle of devices.
    const ur_context_properties_t *
        pProperties, ///< [in][optional] pointer to context creation properties.
    ur_context_handle_t
        *phContext ///< [out] pointer to handle of context object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Makes a reference of the context handle indicating it's in use until
///        paired ::urContextRelease is called
///
/// @details
///     - It is not valid to use a context handle, which has all of its
///       references released.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clRetainContext**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
ur_result_t UR_APICALL urContextRetain(
    ur_context_handle_t
        hContext ///< [in][retain] handle of the context to get a reference of.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Releases the context handle reference indicating end of its usage
///
/// @details
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clReleaseContext**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
ur_result_t UR_APICALL urContextRelease(
    ur_context_handle_t
        hContext ///< [in][release] handle of the context to release.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves various information about context
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clGetContextInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_CONTEXT_INFO_ATOMIC_FENCE_SCOPE_CAPABILITIES < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urContextGetInfo(
    ur_context_handle_t hContext, ///< [in] handle of the context
    ur_context_info_t propName,   ///< [in] type of the info to retrieve
    size_t
        propSize, ///< [in] the number of bytes of memory pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< if propSize is not equal to or greater than the real number of bytes
    ///< needed to return
    ///< the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native context handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeContext`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urContextGetNativeHandle(
    ur_context_handle_t hContext, ///< [in] handle of the context.
    ur_native_handle_t *
        phNativeContext ///< [out] a pointer to the native handle of the context.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime context object from native context handle.
///
/// @details
///     - Creates runtime context handle from native driver context handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hAdapter`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phContext`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urContextCreateWithNativeHandle(
    ur_native_handle_t
        hNativeContext, ///< [in][nocheck] the native handle of the context.
    ur_adapter_handle_t
        hAdapter, ///< [in] handle of the adapter that owns the native handle
    uint32_t numDevices, ///< [in] number of devices associated with the context
    const ur_device_handle_t *
        phDevices, ///< [in][optional][range(0, numDevices)] list of devices associated with
                   ///< the context
    const ur_context_native_properties_t *
        pProperties, ///< [in][optional] pointer to native context properties struct
    ur_context_handle_t *
        phContext ///< [out] pointer to the handle of the context object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Call extended deleter function as callback.
///
/// @details
///     - Calls extended deleter, a user-defined callback to delete context on
///       some platforms.
///     - This is done for performance reasons.
///     - This API might be called directly by an application instead of a
///       runtime backend.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pfnDeleter`
ur_result_t UR_APICALL urContextSetExtendedDeleter(
    ur_context_handle_t hContext, ///< [in] handle of the context.
    ur_context_extended_deleter_t
        pfnDeleter, ///< [in] Function pointer to extended deleter.
    void *
        pUserData ///< [in][out][optional] pointer to data to be passed to callback.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create an image object
///
/// @details
///     - The primary ::ur_image_format_t that must be supported by all the
///       adapters are {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_UNORM_INT8},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_UNORM_INT16},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_SNORM_INT8},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_SNORM_INT16},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_SIGNED_INT8},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_SIGNED_INT16},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_SIGNED_INT32},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_UNSIGNED_INT8},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_UNSIGNED_INT16},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_UNSIGNED_INT32},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_HALF_FLOAT},
///       {UR_IMAGE_CHANNEL_ORDER_RGBA, UR_IMAGE_CHANNEL_TYPE_FLOAT}.
///
/// @remarks
///   _Analogues_
///     - **clCreateImage**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_MEM_FLAGS_MASK & flags`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pImageDesc && UR_STRUCTURE_TYPE_IMAGE_DESC != pImageDesc->stype`
///         + `pImageDesc && UR_MEM_TYPE_IMAGE1D_ARRAY < pImageDesc->type`
///         + `pImageDesc && pImageDesc->numMipLevel != 0`
///         + `pImageDesc && pImageDesc->numSamples != 0`
///         + `pImageDesc && pImageDesc->rowPitch != 0 && pHost == nullptr`
///         + `pImageDesc && pImageDesc->slicePitch != 0 && pHost == nullptr`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_INVALID_HOST_PTR
///         + `pHost == NULL && (flags & (UR_MEM_FLAG_USE_HOST_POINTER | UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER)) != 0`
///         + `pHost != NULL && (flags & (UR_MEM_FLAG_USE_HOST_POINTER | UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER)) == 0`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_IMAGE_FORMAT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urMemImageCreate(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_mem_flags_t flags, ///< [in] allocation and usage information flags
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description
    void *pHost,           ///< [in][optional] pointer to the buffer data
    ur_mem_handle_t *phMem ///< [out] pointer to handle of image object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a memory buffer
///
/// @details
///     - See also ::ur_buffer_channel_properties_t.
///     - See also ::ur_buffer_alloc_location_properties_t.
///
/// @remarks
///   _Analogues_
///     - **clCreateBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_MEM_FLAGS_MASK & flags`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phBuffer`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_BUFFER_SIZE
///         + `size == 0`
///     - ::UR_RESULT_ERROR_INVALID_HOST_PTR
///         + `pProperties == NULL && (flags & (UR_MEM_FLAG_USE_HOST_POINTER | UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER)) != 0`
///         + `pProperties != NULL && pProperties->pHost == NULL && (flags & (UR_MEM_FLAG_USE_HOST_POINTER | UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER)) != 0`
///         + `pProperties != NULL && pProperties->pHost != NULL && (flags & (UR_MEM_FLAG_USE_HOST_POINTER | UR_MEM_FLAG_ALLOC_COPY_HOST_POINTER)) == 0`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urMemBufferCreate(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_mem_flags_t flags, ///< [in] allocation and usage information flags
    size_t size, ///< [in] size in bytes of the memory object to be allocated
    const ur_buffer_properties_t
        *pProperties, ///< [in][optional] pointer to buffer creation properties
    ur_mem_handle_t
        *phBuffer ///< [out] pointer to handle of the memory buffer created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference the memory object. Increment the memory object's
///        reference count
///
/// @details
///     - Useful in library function to retain access to the memory object after
///       the caller released the object
///
/// @remarks
///   _Analogues_
///     - **clRetainMemoryObject**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hMem`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urMemRetain(
    ur_mem_handle_t
        hMem ///< [in][retain] handle of the memory object to get access
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the memory object's reference count and delete the object if
///        the reference count becomes zero.
///
/// @remarks
///   _Analogues_
///     - **clReleaseMemoryObject**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hMem`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urMemRelease(
    ur_mem_handle_t
        hMem ///< [in][release] handle of the memory object to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a sub buffer representing a region in an existing buffer
///
/// @remarks
///   _Analogues_
///     - **clCreateSubBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_MEM_FLAGS_MASK & flags`
///         + `::UR_BUFFER_CREATE_TYPE_REGION < bufferCreateType`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pRegion`
///         + `NULL == phMem`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OBJECT_ALLOCATION_FAILURE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_BUFFER_SIZE
///         + `pRegion && pRegion->size == 0`
///         + hBuffer allocation size < (pRegion->origin + pRegion->size)
///     - ::UR_RESULT_ERROR_INVALID_HOST_PTR
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urMemBufferPartition(
    ur_mem_handle_t
        hBuffer,          ///< [in] handle of the buffer object to allocate from
    ur_mem_flags_t flags, ///< [in] allocation and usage information flags
    ur_buffer_create_type_t bufferCreateType, ///< [in] buffer creation type
    const ur_buffer_region_t
        *pRegion, ///< [in] pointer to buffer create region information
    ur_mem_handle_t
        *phMem ///< [out] pointer to the handle of sub buffer created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native mem handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///     - The implementation may require a valid device handle to return the
///       native mem handle
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hMem`
///         + If `hDevice == NULL` and the implementation requires a valid device.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeMem`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urMemGetNativeHandle(
    ur_mem_handle_t hMem, ///< [in] handle of the mem.
    ur_device_handle_t
        hDevice, ///< [in][optional] handle of the device that the native handle will be
                 ///< resident on.
    ur_native_handle_t
        *phNativeMem ///< [out] a pointer to the native handle of the mem.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime buffer memory object from native memory handle.
///
/// @details
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phMem`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urMemBufferCreateWithNativeHandle(
    ur_native_handle_t
        hNativeMem, ///< [in][nocheck] the native handle to the memory.
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    const ur_mem_native_properties_t *
        pProperties, ///< [in][optional] pointer to native memory creation properties.
    ur_mem_handle_t
        *phMem ///< [out] pointer to handle of buffer memory object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime image memory object from native memory handle.
///
/// @details
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phMem`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urMemImageCreateWithNativeHandle(
    ur_native_handle_t
        hNativeMem, ///< [in][nocheck] the native handle to the memory.
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification.
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description.
    const ur_mem_native_properties_t *
        pProperties, ///< [in][optional] pointer to native memory creation properties.
    ur_mem_handle_t
        *phMem ///< [out] pointer to handle of image memory object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieve information about a memory object.
///
/// @details
///     - Query information that is common to all memory objects.
///
/// @remarks
///   _Analogues_
///     - **clGetMemObjectInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hMemory`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_MEM_INFO_REFERENCE_COUNT < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urMemGetInfo(
    ur_mem_handle_t
        hMemory,            ///< [in] handle to the memory object being queried.
    ur_mem_info_t propName, ///< [in] type of the info to retrieve.
    size_t
        propSize, ///< [in] the number of bytes of memory pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If propSize is less than the real number of bytes needed to return
    ///< the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieve information about an image object.
///
/// @details
///     - Query information specific to an image object.
///
/// @remarks
///   _Analogues_
///     - **clGetImageInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hMemory`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_IMAGE_INFO_DEPTH < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urMemImageGetInfo(
    ur_mem_handle_t hMemory, ///< [in] handle to the image object being queried.
    ur_image_info_t propName, ///< [in] type of image info to retrieve.
    size_t
        propSize, ///< [in] the number of bytes of memory pointer to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If propSize is less than the real number of bytes needed to return
    ///< the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a sampler object in a context
///
/// @details
///     - The props parameter specifies a list of sampler property names and
///       their corresponding values.
///     - The list is terminated with 0. If the list is NULL, default values
///       will be used.
///
/// @remarks
///   _Analogues_
///     - **clCreateSamplerWithProperties**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDesc`
///         + `NULL == phSampler`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_SAMPLER_ADDRESSING_MODE_MIRRORED_REPEAT < pDesc->addressingMode`
///         + `::UR_SAMPLER_FILTER_MODE_LINEAR < pDesc->filterMode`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urSamplerCreate(
    ur_context_handle_t hContext,   ///< [in] handle of the context object
    const ur_sampler_desc_t *pDesc, ///< [in] pointer to the sampler description
    ur_sampler_handle_t
        *phSampler ///< [out] pointer to handle of sampler object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the sampler object handle. Increment its reference
///        count
///
/// @remarks
///   _Analogues_
///     - **clRetainSampler**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hSampler`
///     - ::UR_RESULT_ERROR_INVALID_SAMPLER
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urSamplerRetain(
    ur_sampler_handle_t
        hSampler ///< [in][retain] handle of the sampler object to get access
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the sampler's reference count and delete the sampler if the
///        reference count becomes zero.
///
/// @remarks
///   _Analogues_
///     - **clReleaseSampler**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hSampler`
///     - ::UR_RESULT_ERROR_INVALID_SAMPLER
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urSamplerRelease(
    ur_sampler_handle_t
        hSampler ///< [in][release] handle of the sampler object to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query information about a sampler object
///
/// @remarks
///   _Analogues_
///     - **clGetSamplerInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hSampler`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_SAMPLER_INFO_FILTER_MODE < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_SAMPLER
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urSamplerGetInfo(
    ur_sampler_handle_t hSampler, ///< [in] handle of the sampler object
    ur_sampler_info_t propName, ///< [in] name of the sampler property to query
    size_t
        propSize, ///< [in] size in bytes of the sampler property value provided
    void *
        pPropValue, ///< [out][typename(propName, propSize)][optional] value of the sampler
                    ///< property
    size_t *
        pPropSizeRet ///< [out][optional] size in bytes returned in sampler property value
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return sampler native sampler handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability sampler extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hSampler`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeSampler`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urSamplerGetNativeHandle(
    ur_sampler_handle_t hSampler, ///< [in] handle of the sampler.
    ur_native_handle_t *
        phNativeSampler ///< [out] a pointer to the native handle of the sampler.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime sampler object from native sampler handle.
///
/// @details
///     - Creates runtime sampler handle from native driver sampler handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phSampler`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urSamplerCreateWithNativeHandle(
    ur_native_handle_t
        hNativeSampler, ///< [in][nocheck] the native handle of the sampler.
    ur_context_handle_t hContext, ///< [in] handle of the context object
    const ur_sampler_native_properties_t *
        pProperties, ///< [in][optional] pointer to native sampler properties struct.
    ur_sampler_handle_t *
        phSampler ///< [out] pointer to the handle of the sampler object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief USM allocate host memory
///
/// @details
///     - If pUSMDesc is not NULL and pUSMDesc->pool is not NULL the allocation
///       will be served from a specified memory pool.
///     - Otherwise, the behavior is implementation-defined.
///     - Allocations served from different memory pools must be isolated and
///       must not reside on the same page.
///     - Any flags/hints passed through pUSMDesc only affect the single
///       allocation.
///     - See also ::ur_usm_host_desc_t.
///     - See also ::ur_usm_alloc_location_desc_t.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pUSMDesc && ::UR_USM_ADVICE_FLAGS_MASK & pUSMDesc->hints`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If ::UR_DEVICE_INFO_USM_HOST_SUPPORT is false.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pUSMDesc && pUSMDesc->align != 0 && ((pUSMDesc->align & (pUSMDesc->align-1)) != 0)`
///         + If `align` is greater that the size of the largest data type supported by `hDevice`.
///     - ::UR_RESULT_ERROR_INVALID_USM_SIZE
///         + `size == 0`
///         + `size` is greater than ::UR_DEVICE_INFO_MAX_MEM_ALLOC_SIZE.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If any device associated with `hContext` reports `false` for ::UR_DEVICE_INFO_USM_POOL_SUPPORT
ur_result_t UR_APICALL urUSMHostAlloc(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    const ur_usm_desc_t
        *pUSMDesc, ///< [in][optional] USM memory allocation descriptor
    ur_usm_pool_handle_t
        pool, ///< [in][optional] Pointer to a pool created using urUSMPoolCreate
    size_t
        size, ///< [in] minimum size in bytes of the USM memory object to be allocated
    void **ppMem ///< [out] pointer to USM host memory object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief USM allocate device memory
///
/// @details
///     - If pUSMDesc is not NULL and pUSMDesc->pool is not NULL the allocation
///       will be served from a specified memory pool.
///     - Otherwise, the behavior is implementation-defined.
///     - Allocations served from different memory pools must be isolated and
///       must not reside on the same page.
///     - Any flags/hints passed through pUSMDesc only affect the single
///       allocation.
///     - See also ::ur_usm_device_desc_t.
///     - See also ::ur_usm_alloc_location_desc_t.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pUSMDesc && ::UR_USM_ADVICE_FLAGS_MASK & pUSMDesc->hints`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If ::UR_DEVICE_INFO_USM_HOST_SUPPORT is false.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pUSMDesc && pUSMDesc->align != 0 && ((pUSMDesc->align & (pUSMDesc->align-1)) != 0)`
///         + If `align` is greater that the size of the largest data type supported by `hDevice`.
///     - ::UR_RESULT_ERROR_INVALID_USM_SIZE
///         + `size == 0`
///         + `size` is greater than ::UR_DEVICE_INFO_MAX_MEM_ALLOC_SIZE.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If any device associated with `hContext` reports `false` for ::UR_DEVICE_INFO_USM_POOL_SUPPORT
ur_result_t UR_APICALL urUSMDeviceAlloc(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_usm_desc_t
        *pUSMDesc, ///< [in][optional] USM memory allocation descriptor
    ur_usm_pool_handle_t
        pool, ///< [in][optional] Pointer to a pool created using urUSMPoolCreate
    size_t
        size, ///< [in] minimum size in bytes of the USM memory object to be allocated
    void **ppMem ///< [out] pointer to USM device memory object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief USM allocate shared memory
///
/// @details
///     - If pUSMDesc is not NULL and pUSMDesc->pool is not NULL the allocation
///       will be served from a specified memory pool.
///     - Otherwise, the behavior is implementation-defined.
///     - Allocations served from different memory pools must be isolated and
///       must not reside on the same page.
///     - Any flags/hints passed through pUSMDesc only affect the single
///       allocation.
///     - See also ::ur_usm_host_desc_t.
///     - See also ::ur_usm_device_desc_t.
///     - See also ::ur_usm_alloc_location_desc_t.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pUSMDesc && ::UR_USM_ADVICE_FLAGS_MASK & pUSMDesc->hints`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pUSMDesc && pUSMDesc->align != 0 && ((pUSMDesc->align & (pUSMDesc->align-1)) != 0)`
///         + If `align` is greater that the size of the largest data type supported by `hDevice`.
///     - ::UR_RESULT_ERROR_INVALID_USM_SIZE
///         + `size == 0`
///         + `size` is greater than ::UR_DEVICE_INFO_MAX_MEM_ALLOC_SIZE.
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If `UR_DEVICE_INFO_USM_SINGLE_SHARED_SUPPORT` and `UR_DEVICE_INFO_USM_CROSS_SHARED_SUPPORT` are both false.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If any device associated with `hContext` reports `false` for ::UR_DEVICE_INFO_USM_POOL_SUPPORT
ur_result_t UR_APICALL urUSMSharedAlloc(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_usm_desc_t *
        pUSMDesc, ///< [in][optional] Pointer to USM memory allocation descriptor.
    ur_usm_pool_handle_t
        pool, ///< [in][optional] Pointer to a pool created using urUSMPoolCreate
    size_t
        size, ///< [in] minimum size in bytes of the USM memory object to be allocated
    void **ppMem ///< [out] pointer to USM shared memory object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Free the USM memory object
///
/// @details
///     - Note that implementations are required to wait for previously enqueued
///       commands that may be accessing `pMem` to finish before freeing the
///       memory.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urUSMFree(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    void *pMem                    ///< [in] pointer to USM memory object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get USM memory object allocation information
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_ALLOC_INFO_POOL < propName`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urUSMGetMemAllocInfo(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    const void *pMem,             ///< [in] pointer to USM memory object
    ur_usm_alloc_info_t
        propName, ///< [in] the name of the USM allocation property to query
    size_t
        propSize, ///< [in] size in bytes of the USM allocation property value
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the USM
                    ///< allocation property
    size_t *
        pPropSizeRet ///< [out][optional] bytes returned in USM allocation property
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create USM memory pool with desired properties.
///
/// @details
///     - UR can create multiple instances of the pool depending on allocation
///       requests.
///     - See also ::ur_usm_pool_limits_desc_t.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pPoolDesc`
///         + `NULL == ppPool`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_POOL_FLAGS_MASK & pPoolDesc->flags`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If any device associated with `hContext` reports `false` for ::UR_DEVICE_INFO_USM_POOL_SUPPORT
ur_result_t UR_APICALL urUSMPoolCreate(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_usm_pool_desc_t *
        pPoolDesc, ///< [in] pointer to USM pool descriptor. Can be chained with
                   ///< ::ur_usm_pool_limits_desc_t
    ur_usm_pool_handle_t *ppPool ///< [out] pointer to USM memory pool
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the pool handle. Increment its reference count
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == pPool`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urUSMPoolRetain(
    ur_usm_pool_handle_t pPool ///< [in][retain] pointer to USM memory pool
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the pool's reference count and delete the pool if the
///        reference count becomes zero.
///
/// @details
///     - All allocation belonging to the pool must be freed prior to the the
///       reference count becoming zero.
///     - If the pool is deleted, this function returns all its reserved memory
///       to the driver.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == pPool`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urUSMPoolRelease(
    ur_usm_pool_handle_t pPool ///< [in][release] pointer to USM memory pool
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query information about a USM memory pool
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPool`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_POOL_INFO_CONTEXT < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urUSMPoolGetInfo(
    ur_usm_pool_handle_t hPool,  ///< [in] handle of the USM memory pool
    ur_usm_pool_info_t propName, ///< [in] name of the pool property to query
    size_t propSize, ///< [in] size in bytes of the pool property value provided
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the pool
                    ///< property
    size_t *
        pPropSizeRet ///< [out][optional] size in bytes returned in pool property value
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get information about the minimum and recommended granularity of
///        physical and virtual memory.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_VIRTUAL_MEM_GRANULARITY_INFO_RECOMMENDED < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urVirtualMemGranularityGetInfo(
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    ur_device_handle_t
        hDevice, ///< [in][optional] is the device to get the granularity from, if the
    ///< device is null then the granularity is suitable for all devices in context.
    ur_virtual_mem_granularity_info_t
        propName, ///< [in] type of the info to query.
    size_t
        propSize, ///< [in] size in bytes of the memory pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
    ///< the info. If propSize is less than the real number of bytes needed to
    ///< return the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is
    ///< returned and pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName."
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Reserve a virtual memory range.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppStart`
ur_result_t UR_APICALL urVirtualMemReserve(
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    const void *
        pStart, ///< [in][optional] pointer to the start of the virtual memory region to
    ///< reserve, specifying a null value causes the implementation to select a
    ///< start address.
    size_t
        size, ///< [in] size in bytes of the virtual address range to reserve.
    void **
        ppStart ///< [out] pointer to the returned address at the start of reserved virtual
                ///< memory range.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Free a virtual memory range.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pStart`
ur_result_t UR_APICALL urVirtualMemFree(
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    const void *
        pStart, ///< [in] pointer to the start of the virtual memory range to free.
    size_t size ///< [in] size in bytes of the virtual memory range to free.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Map a virtual memory range to a physical memory handle.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hPhysicalMem`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pStart`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_VIRTUAL_MEM_ACCESS_FLAGS_MASK & flags`
ur_result_t UR_APICALL urVirtualMemMap(
    ur_context_handle_t hContext, ///< [in] handle to the context object.
    const void
        *pStart, ///< [in] pointer to the start of the virtual memory range.
    size_t size, ///< [in] size in bytes of the virtual memory range to map.
    ur_physical_mem_handle_t
        hPhysicalMem, ///< [in] handle of the physical memory to map pStart to.
    size_t
        offset, ///< [in] offset in bytes into the physical memory to map pStart to.
    ur_virtual_mem_access_flags_t
        flags ///< [in] access flags for the physical memory mapping.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Unmap a virtual memory range previously mapped in a context.
///
/// @details
///     - After a call to this function, the virtual memory range is left in a
///       state ready to be remapped.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pStart`
ur_result_t UR_APICALL urVirtualMemUnmap(
    ur_context_handle_t hContext, ///< [in] handle to the context object.
    const void *
        pStart, ///< [in] pointer to the start of the mapped virtual memory range
    size_t size ///< [in] size in bytes of the virtual memory range.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set the access mode of a mapped virtual memory range.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pStart`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_VIRTUAL_MEM_ACCESS_FLAGS_MASK & flags`
ur_result_t UR_APICALL urVirtualMemSetAccess(
    ur_context_handle_t hContext, ///< [in] handle to the context object.
    const void
        *pStart, ///< [in] pointer to the start of the virtual memory range.
    size_t size, ///< [in] size in bytes of the virtual memory range.
    ur_virtual_mem_access_flags_t
        flags ///< [in] access flags to set for the mapped virtual memory range.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get information about a mapped virtual memory range.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pStart`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_VIRTUAL_MEM_INFO_ACCESS_MODE < propName`
ur_result_t UR_APICALL urVirtualMemGetInfo(
    ur_context_handle_t hContext, ///< [in] handle to the context object.
    const void
        *pStart, ///< [in] pointer to the start of the virtual memory range.
    size_t size, ///< [in] size in bytes of the virtual memory range.
    ur_virtual_mem_info_t propName, ///< [in] type of the info to query.
    size_t
        propSize, ///< [in] size in bytes of the memory pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
    ///< the info. If propSize is less than the real number of bytes needed to
    ///< return the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is
    ///< returned and pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName."
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a physical memory handle that virtual memory can be mapped to.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_PHYSICAL_MEM_FLAGS_MASK & pProperties->flags`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phPhysicalMem`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If size is not a multiple of ::UR_VIRTUAL_MEM_GRANULARITY_INFO_MINIMUM.
ur_result_t UR_APICALL urPhysicalMemCreate(
    ur_context_handle_t hContext, ///< [in] handle of the context object.
    ur_device_handle_t hDevice,   ///< [in] handle of the device object.
    size_t
        size, ///< [in] size in bytes of physical memory to allocate, must be a multiple
              ///< of ::UR_VIRTUAL_MEM_GRANULARITY_INFO_MINIMUM.
    const ur_physical_mem_properties_t *
        pProperties, ///< [in][optional] pointer to physical memory creation properties.
    ur_physical_mem_handle_t *
        phPhysicalMem ///< [out] pointer to handle of physical memory object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retain a physical memory handle, increment its reference count.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPhysicalMem`
ur_result_t UR_APICALL urPhysicalMemRetain(
    ur_physical_mem_handle_t
        hPhysicalMem ///< [in][retain] handle of the physical memory object to retain.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release a physical memory handle, decrement its reference count.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hPhysicalMem`
ur_result_t UR_APICALL urPhysicalMemRelease(
    ur_physical_mem_handle_t
        hPhysicalMem ///< [in][release] handle of the physical memory object to release.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a program object from input intermediate language.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The adapter may (but is not required to) perform validation of the
///       provided module during this call.
///
/// @remarks
///   _Analogues_
///     - **clCreateProgramWithIL**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pIL`
///         + `NULL == phProgram`
///         + `NULL != pProperties && pProperties->count > 0 && NULL == pProperties->pMetadatas`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NULL != pProperties && NULL != pProperties->pMetadatas && pProperties->count == 0`
///         + `length == 0`
///     - ::UR_RESULT_ERROR_INVALID_BINARY
///         + If `pIL` is not a valid IL binary for devices in `hContext`.
///     - ::UR_RESULT_ERROR_COMPILER_NOT_AVAILABLE
///         + If devices in `hContext` don't have the capability to compile an IL binary at runtime.
ur_result_t UR_APICALL urProgramCreateWithIL(
    ur_context_handle_t hContext, ///< [in] handle of the context instance
    const void *pIL,              ///< [in] pointer to IL binary.
    size_t length,                ///< [in] length of `pIL` in bytes.
    const ur_program_properties_t *
        pProperties, ///< [in][optional] pointer to program creation properties.
    ur_program_handle_t
        *phProgram ///< [out] pointer to handle of program object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a program object from native binaries for the specified
///        devices.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point, `phProgram` will
///       contain binaries of type ::UR_PROGRAM_BINARY_TYPE_COMPILED_OBJECT or
///       ::UR_PROGRAM_BINARY_TYPE_LIBRARY for the specified devices in
///       `phDevices`.
///     - The devices specified by `phDevices` must be associated with the
///       context.
///     - The adapter may (but is not required to) perform validation of the
///       provided modules during this call.
///
/// @remarks
///   _Analogues_
///     - **clCreateProgramWithBinary**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevices`
///         + `NULL == pLengths`
///         + `NULL == ppBinaries`
///         + `NULL == phProgram`
///         + `NULL != pProperties && pProperties->count > 0 && NULL == pProperties->pMetadatas`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `NULL != pProperties && NULL != pProperties->pMetadatas && pProperties->count == 0`
///         + `numDevices == 0`
///     - ::UR_RESULT_ERROR_INVALID_NATIVE_BINARY
///         + If any binary in `ppBinaries` isn't a valid binary for the corresponding device in `phDevices.`
ur_result_t UR_APICALL urProgramCreateWithBinary(
    ur_context_handle_t hContext, ///< [in] handle of the context instance
    uint32_t numDevices,          ///< [in] number of devices
    ur_device_handle_t *
        phDevices, ///< [in][range(0, numDevices)] a pointer to a list of device handles. The
                   ///< binaries are loaded for devices specified in this list.
    size_t *
        pLengths, ///< [in][range(0, numDevices)] array of sizes of program binaries
                  ///< specified by `pBinaries` (in bytes).
    const uint8_t **
        ppBinaries, ///< [in][range(0, numDevices)] pointer to program binaries to be loaded
                    ///< for devices specified by `phDevices`.
    const ur_program_properties_t *
        pProperties, ///< [in][optional] pointer to program creation properties.
    ur_program_handle_t
        *phProgram ///< [out] pointer to handle of Program object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one program, negates need for the
///        linking step.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point, the program passed
///       will contain a binary of the ::UR_PROGRAM_BINARY_TYPE_EXECUTABLE type
///       for each device in `hContext`.
///
/// @remarks
///   _Analogues_
///     - **clBuildProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If `hProgram` isn't a valid program object.
///     - ::UR_RESULT_ERROR_PROGRAM_BUILD_FAILURE
///         + If an error occurred when building `hProgram`.
ur_result_t UR_APICALL urProgramBuild(
    ur_context_handle_t hContext, ///< [in] handle of the context instance.
    ur_program_handle_t hProgram, ///< [in] Handle of the program to build.
    const char *
        pOptions ///< [in][optional] pointer to build options null-terminated string.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one or more programs.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point `hProgram` will
///       contain a binary of the ::UR_PROGRAM_BINARY_TYPE_COMPILED_OBJECT type
///       for each device in `hContext`.
///
/// @remarks
///   _Analogues_
///     - **clCompileProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If `hProgram` isn't a valid program object.
///     - ::UR_RESULT_ERROR_PROGRAM_BUILD_FAILURE
///         + If an error occurred while compiling `hProgram`.
ur_result_t UR_APICALL urProgramCompile(
    ur_context_handle_t hContext, ///< [in] handle of the context instance.
    ur_program_handle_t
        hProgram, ///< [in][out] handle of the program to compile.
    const char *
        pOptions ///< [in][optional] pointer to build options null-terminated string.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one or more programs.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point the program returned
///       in `phProgram` will contain a binary of the
///       ::UR_PROGRAM_BINARY_TYPE_EXECUTABLE type for each device in
///       `hContext`.
///     - If a non-success code is returned and `phProgram` is not `nullptr`, it
///       will contain an unspecified program or `nullptr`. Implementations may
///       use the build log of this program (accessible via
///       ::urProgramGetBuildInfo) to provide an error log for the linking
///       failure.
///
/// @remarks
///   _Analogues_
///     - **clLinkProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phPrograms`
///         + `NULL == phProgram`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If one of the programs in `phPrograms` isn't a valid program object.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `count == 0`
///     - ::UR_RESULT_ERROR_PROGRAM_LINK_FAILURE
///         + If an error occurred while linking `phPrograms`.
ur_result_t UR_APICALL urProgramLink(
    ur_context_handle_t hContext, ///< [in] handle of the context instance.
    uint32_t count, ///< [in] number of program handles in `phPrograms`.
    const ur_program_handle_t *
        phPrograms, ///< [in][range(0, count)] pointer to array of program handles.
    const char *
        pOptions, ///< [in][optional] pointer to linker options null-terminated string.
    ur_program_handle_t
        *phProgram ///< [out] pointer to handle of program object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the Program object.
///
/// @details
///     - Get a reference to the Program object handle. Increment its reference
///       count
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clRetainProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
ur_result_t UR_APICALL urProgramRetain(
    ur_program_handle_t
        hProgram ///< [in][retain] handle for the Program to retain
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release Program.
///
/// @details
///     - Decrement reference count and destroy the Program if reference count
///       becomes zero.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clReleaseProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
ur_result_t UR_APICALL urProgramRelease(
    ur_program_handle_t
        hProgram ///< [in][release] handle for the Program to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves a device function pointer to a user-defined function.
///
/// @details
///     - Retrieves a pointer to the functions with the given name and defined
///       in the given program.
///     - ::UR_RESULT_ERROR_FUNCTION_ADDRESS_NOT_AVAILABLE is returned if the
///       function can not be obtained.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clGetDeviceFunctionPointerINTEL**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pFunctionName`
///         + `NULL == ppFunctionPointer`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_NAME
///         + If `pFunctionName` couldn't be found in `hProgram`.
///     - ::UR_RESULT_ERROR_FUNCTION_ADDRESS_NOT_AVAILABLE
///         + If `pFunctionName` could be located, but its address couldn't be retrieved.
ur_result_t UR_APICALL urProgramGetFunctionPointer(
    ur_device_handle_t
        hDevice, ///< [in] handle of the device to retrieve pointer for.
    ur_program_handle_t
        hProgram, ///< [in] handle of the program to search for function in.
    ///< The program must already be built to the specified device, or
    ///< otherwise ::UR_RESULT_ERROR_INVALID_PROGRAM_EXECUTABLE is returned.
    const char *
        pFunctionName, ///< [in] A null-terminates string denoting the mangled function name.
    void **
        ppFunctionPointer ///< [out] Returns the pointer to the function if it is found in the program.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves a pointer to a device global variable.
///
/// @details
///     - Retrieves a pointer to a device global variable.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @remarks
///   _Analogues_
///     - **clGetDeviceGlobalVariablePointerINTEL**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalVariableName`
///         + `NULL == ppGlobalVariablePointerRet`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `name` is not a valid variable in the program.
ur_result_t UR_APICALL urProgramGetGlobalVariablePointer(
    ur_device_handle_t
        hDevice, ///< [in] handle of the device to retrieve the pointer for.
    ur_program_handle_t
        hProgram, ///< [in] handle of the program where the global variable is.
    const char *
        pGlobalVariableName, ///< [in] mangled name of the global variable to retrieve the pointer for.
    size_t *
        pGlobalVariableSizeRet, ///< [out][optional] Returns the size of the global variable if it is found
                                ///< in the program.
    void **
        ppGlobalVariablePointerRet ///< [out] Returns the pointer to the global variable if it is found in the program.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query information about a Program object
///
/// @remarks
///   _Analogues_
///     - **clGetProgramInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_PROGRAM_INFO_KERNEL_NAMES < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urProgramGetInfo(
    ur_program_handle_t hProgram, ///< [in] handle of the Program object
    ur_program_info_t propName, ///< [in] name of the Program property to query
    size_t propSize,            ///< [in] the size of the Program property.
    void *
        pPropValue, ///< [in,out][optional][typename(propName, propSize)] array of bytes of
                    ///< holding the program info property.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return
    ///< the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query build information about a Program object for a Device
///
/// @remarks
///   _Analogues_
///     - **clGetProgramBuildInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_PROGRAM_BUILD_INFO_BINARY_TYPE < propName`
ur_result_t UR_APICALL urProgramGetBuildInfo(
    ur_program_handle_t hProgram, ///< [in] handle of the Program object
    ur_device_handle_t hDevice,   ///< [in] handle of the Device object
    ur_program_build_info_t
        propName,    ///< [in] name of the Program build info to query
    size_t propSize, ///< [in] size of the Program build info property.
    void *
        pPropValue, ///< [in,out][optional][typename(propName, propSize)] value of the Program
                    ///< build property.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return the info then the ::UR_RESULT_ERROR_INVALID_SIZE
    ///< error is returned and pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of data being
                     ///< queried by propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set an array of specialization constants on a Program.
///
/// @details
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///     - `hProgram` must have been created with the ::urProgramCreateWithIL
///       entry point.
///     - Any spec constants set with this entry point will apply only to
///       subsequent calls to ::urProgramBuild or ::urProgramCompile.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSpecConstants`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `count == 0`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + A pSpecConstant entry contains a size that does not match that of the specialization constant in the module.
///         + A pSpecConstant entry contains a nullptr pValue.
///     - ::UR_RESULT_ERROR_INVALID_SPEC_ID
///         + Any id specified in a pSpecConstant entry is not a valid specialization constant identifier.
ur_result_t UR_APICALL urProgramSetSpecializationConstants(
    ur_program_handle_t hProgram, ///< [in] handle of the Program object
    uint32_t count, ///< [in] the number of elements in the pSpecConstants array
    const ur_specialization_constant_info_t *
        pSpecConstants ///< [in][range(0, count)] array of specialization constant value
                       ///< descriptions
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return program native program handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability program extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeProgram`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urProgramGetNativeHandle(
    ur_program_handle_t hProgram, ///< [in] handle of the program.
    ur_native_handle_t *
        phNativeProgram ///< [out] a pointer to the native handle of the program.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime program object from native program handle.
///
/// @details
///     - Creates runtime program handle from native driver program handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phProgram`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urProgramCreateWithNativeHandle(
    ur_native_handle_t
        hNativeProgram, ///< [in][nocheck] the native handle of the program.
    ur_context_handle_t hContext, ///< [in] handle of the context instance
    const ur_program_native_properties_t *
        pProperties, ///< [in][optional] pointer to native program properties struct.
    ur_program_handle_t *
        phProgram ///< [out] pointer to the handle of the program object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create kernel object from a program.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pKernelName`
///         + `NULL == phKernel`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_NAME
///         + If `pKernelName` wasn't found in `hProgram`.
ur_result_t UR_APICALL urKernelCreate(
    ur_program_handle_t hProgram, ///< [in] handle of the program instance
    const char *pKernelName,      ///< [in] pointer to null-terminated string.
    ur_kernel_handle_t
        *phKernel ///< [out] pointer to handle of kernel object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set kernel argument to a value.
///
/// @details
///     - The application may call this function from simultaneous threads with
///       the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pArgValue`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE
ur_result_t UR_APICALL urKernelSetArgValue(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t argIndex, ///< [in] argument index in range [0, num args - 1]
    size_t argSize,    ///< [in] size of argument type
    const ur_kernel_arg_value_properties_t
        *pProperties, ///< [in][optional] pointer to value properties.
    const void
        *pArgValue ///< [in] argument value represented as matching arg type.
    ///< The data pointed to will be copied and therefore can be reused on return.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set kernel argument to a local buffer.
///
/// @details
///     - The application may call this function from simultaneous threads with
///       the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE
ur_result_t UR_APICALL urKernelSetArgLocal(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t argIndex, ///< [in] argument index in range [0, num args - 1]
    size_t
        argSize, ///< [in] size of the local buffer to be allocated by the runtime
    const ur_kernel_arg_local_properties_t
        *pProperties ///< [in][optional] pointer to local buffer properties.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query information about a Kernel object
///
/// @remarks
///   _Analogues_
///     - **clGetKernelInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_KERNEL_INFO_NUM_REGS < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urKernelGetInfo(
    ur_kernel_handle_t hKernel, ///< [in] handle of the Kernel object
    ur_kernel_info_t propName,  ///< [in] name of the Kernel property to query
    size_t propSize,            ///< [in] the size of the Kernel property value.
    void *
        pPropValue, ///< [in,out][optional][typename(propName, propSize)] array of bytes
                    ///< holding the kernel info property.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return
    ///< the info then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of data being
                     ///< queried by propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query work Group information about a Kernel object
///
/// @remarks
///   _Analogues_
///     - **clGetKernelWorkGroupInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_KERNEL_GROUP_INFO_COMPILE_MAX_LINEAR_WORK_GROUP_SIZE < propName`
ur_result_t UR_APICALL urKernelGetGroupInfo(
    ur_kernel_handle_t hKernel, ///< [in] handle of the Kernel object
    ur_device_handle_t hDevice, ///< [in] handle of the Device object
    ur_kernel_group_info_t
        propName,    ///< [in] name of the work Group property to query
    size_t propSize, ///< [in] size of the Kernel Work Group property value
    void *
        pPropValue, ///< [in,out][optional][typename(propName, propSize)] value of the Kernel
                    ///< Work Group property.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of data being
                     ///< queried by propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query SubGroup information about a Kernel object
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_KERNEL_SUB_GROUP_INFO_SUB_GROUP_SIZE_INTEL < propName`
ur_result_t UR_APICALL urKernelGetSubGroupInfo(
    ur_kernel_handle_t hKernel, ///< [in] handle of the Kernel object
    ur_device_handle_t hDevice, ///< [in] handle of the Device object
    ur_kernel_sub_group_info_t
        propName,    ///< [in] name of the SubGroup property to query
    size_t propSize, ///< [in] size of the Kernel SubGroup property value
    void *
        pPropValue, ///< [in,out][optional][typename(propName, propSize)] value of the Kernel
                    ///< SubGroup property.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of data being
                     ///< queried by propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the Kernel object.
///
/// @details
///     - Get a reference to the Kernel object handle. Increment its reference
///       count
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clRetainKernel**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
ur_result_t UR_APICALL urKernelRetain(
    ur_kernel_handle_t hKernel ///< [in][retain] handle for the Kernel to retain
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release Kernel.
///
/// @details
///     - Decrement reference count and destroy the Kernel if reference count
///       becomes zero.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clReleaseKernel**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
ur_result_t UR_APICALL urKernelRelease(
    ur_kernel_handle_t
        hKernel ///< [in][release] handle for the Kernel to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set a USM pointer as the argument value of a Kernel.
///
/// @details
///     - The application may call this function from simultaneous threads with
///       the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clSetKernelArgSVMPointer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE
ur_result_t UR_APICALL urKernelSetArgPointer(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t argIndex, ///< [in] argument index in range [0, num args - 1]
    const ur_kernel_arg_pointer_properties_t
        *pProperties, ///< [in][optional] pointer to USM pointer properties.
    const void *
        pArgValue ///< [in][optional] Pointer obtained by USM allocation or virtual memory
    ///< mapping operation. If null then argument value is considered null.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set additional Kernel execution attributes.
///
/// @details
///     - The application must **not** call this function from simultaneous
///       threads with the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @remarks
///   _Analogues_
///     - **clSetKernelExecInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_KERNEL_EXEC_INFO_CACHE_CONFIG < propName`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pPropValue`
ur_result_t UR_APICALL urKernelSetExecInfo(
    ur_kernel_handle_t hKernel,     ///< [in] handle of the kernel object
    ur_kernel_exec_info_t propName, ///< [in] name of the execution attribute
    size_t propSize,                ///< [in] size in byte the attribute value
    const ur_kernel_exec_info_properties_t
        *pProperties, ///< [in][optional] pointer to execution info properties.
    const void *
        pPropValue ///< [in][typename(propName, propSize)] pointer to memory location holding
                   ///< the property value.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set a Sampler object as the argument value of a Kernel.
///
/// @details
///     - The application may call this function from simultaneous threads with
///       the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///         + `NULL == hArgValue`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
ur_result_t UR_APICALL urKernelSetArgSampler(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t argIndex, ///< [in] argument index in range [0, num args - 1]
    const ur_kernel_arg_sampler_properties_t
        *pProperties, ///< [in][optional] pointer to sampler properties.
    ur_sampler_handle_t hArgValue ///< [in] handle of Sampler object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set a Memory object as the argument value of a Kernel.
///
/// @details
///     - The application may call this function from simultaneous threads with
///       the same kernel handle.
///     - The implementation of this function should be lock-free.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_MEM_FLAGS_MASK & pProperties->memoryAccess`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
ur_result_t UR_APICALL urKernelSetArgMemObj(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t argIndex, ///< [in] argument index in range [0, num args - 1]
    const ur_kernel_arg_mem_obj_properties_t
        *pProperties, ///< [in][optional] pointer to Memory object properties.
    ur_mem_handle_t hArgValue ///< [in][optional] handle of Memory object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set an array of specialization constants on a Kernel.
///
/// @details
///     - This entry point is optional, the application should query for support
///       with device query ::UR_DEVICE_INFO_KERNEL_SET_SPECIALIZATION_CONSTANTS
///       passed to ::urDeviceGetInfo.
///     - Adapters which are capable of setting specialization constants
///       immediately prior to ::urEnqueueKernelLaunch with low overhead should
///       implement this entry point.
///     - Otherwise, if setting specialization constants late requires
///       recompiling or linking a program, adapters should not implement this
///       entry point.
///     - The application may call this function from simultaneous threads for
///       the same device.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSpecConstants`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `count == 0`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If ::UR_DEVICE_INFO_KERNEL_SET_SPECIALIZATION_CONSTANTS query is false
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + A pSpecConstant entry contains a size that does not match that of the specialization constant in the module.
///         + A pSpecConstant entry contains a nullptr pValue.
///     - ::UR_RESULT_ERROR_INVALID_SPEC_ID
///         + Any id specified in a pSpecConstant entry is not a valid specialization constant identifier.
ur_result_t UR_APICALL urKernelSetSpecializationConstants(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t count, ///< [in] the number of elements in the pSpecConstants array
    const ur_specialization_constant_info_t *
        pSpecConstants ///< [in] array of specialization constant value descriptions
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native kernel handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeKernel`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urKernelGetNativeHandle(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel.
    ur_native_handle_t
        *phNativeKernel ///< [out] a pointer to the native handle of the kernel.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime kernel object from native kernel handle.
///
/// @details
///     - Creates runtime kernel handle from native driver kernel handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///     - The implementation may require a valid program handle to return the
///       native kernel handle
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + If `hProgram == NULL` and the implementation requires a valid program.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phKernel`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urKernelCreateWithNativeHandle(
    ur_native_handle_t
        hNativeKernel, ///< [in][nocheck] the native handle of the kernel.
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_program_handle_t
        hProgram, ///< [in][optional] handle of the program associated with the kernel
    const ur_kernel_native_properties_t *
        pProperties, ///< [in][optional] pointer to native kernel properties struct
    ur_kernel_handle_t
        *phKernel ///< [out] pointer to the handle of the kernel object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the suggested local work size for a kernel.
///
/// @details
///     - Query a suggested local work size for a kernel given a global size for
///       each dimension.
///     - The application may call this function from simultaneous threads for
///       the same context.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalWorkOffset`
///         + `NULL == pGlobalWorkSize`
///         + `NULL == pSuggestedLocalWorkSize`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urKernelGetSuggestedLocalWorkSize(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel
    ur_queue_handle_t hQueue,   ///< [in] handle of the queue object
    uint32_t
        numWorkDim, ///< [in] number of dimensions, from 1 to 3, to specify the global
                    ///< and work-group work-items
    const size_t *
        pGlobalWorkOffset, ///< [in] pointer to an array of numWorkDim unsigned values that specify
    ///< the offset used to calculate the global ID of a work-item
    const size_t *
        pGlobalWorkSize, ///< [in] pointer to an array of numWorkDim unsigned values that specify
    ///< the number of global work-items in workDim that will execute the
    ///< kernel function
    size_t *
        pSuggestedLocalWorkSize ///< [out] pointer to an array of numWorkDim unsigned values that specify
    ///< suggested local work size that will contain the result of the query
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query information about a command queue
///
/// @remarks
///   _Analogues_
///     - **clGetCommandQueueInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_QUEUE_INFO_EMPTY < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE - "If `hQueue` isn't a valid queue handle or if `propName` isn't supported by `hQueue`."
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urQueueGetInfo(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_queue_info_t propName, ///< [in] name of the queue property to query
    size_t
        propSize, ///< [in] size in bytes of the queue property value provided
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the queue
                    ///< property
    size_t *
        pPropSizeRet ///< [out][optional] size in bytes returned in queue property value
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a command queue for a device in a context
///
/// @details
///     - See also ::ur_queue_index_properties_t.
///
/// @remarks
///   _Analogues_
///     - **clCreateCommandQueueWithProperties**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_QUEUE_FLAGS_MASK & pProperties->flags`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phQueue`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_INVALID_QUEUE_PROPERTIES
///         + `pProperties != NULL && pProperties->flags & UR_QUEUE_FLAG_PRIORITY_HIGH && pProperties->flags & UR_QUEUE_FLAG_PRIORITY_LOW`
///         + `pProperties != NULL && pProperties->flags & UR_QUEUE_FLAG_SUBMISSION_BATCHED && pProperties->flags & UR_QUEUE_FLAG_SUBMISSION_IMMEDIATE`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urQueueCreate(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_queue_properties_t
        *pProperties, ///< [in][optional] pointer to queue creation properties.
    ur_queue_handle_t
        *phQueue ///< [out] pointer to handle of queue object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to the command queue handle. Increment the command
///        queue's reference count
///
/// @details
///     - Useful in library function to retain access to the command queue after
///       the caller released the queue.
///
/// @remarks
///   _Analogues_
///     - **clRetainCommandQueue**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urQueueRetain(
    ur_queue_handle_t
        hQueue ///< [in][retain] handle of the queue object to get access
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the command queue's reference count and delete the command
///        queue if the reference count becomes zero.
///
/// @details
///     - After the command queue reference count becomes zero and all queued
///       commands in the queue have finished, the queue is deleted.
///     - It also performs an implicit flush to issue all previously queued
///       commands in the queue.
///
/// @remarks
///   _Analogues_
///     - **clReleaseCommandQueue**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urQueueRelease(
    ur_queue_handle_t
        hQueue ///< [in][release] handle of the queue object to release
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return queue native queue handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability queue extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeQueue`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urQueueGetNativeHandle(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue.
    ur_queue_native_desc_t
        *pDesc, ///< [in][optional] pointer to native descriptor
    ur_native_handle_t
        *phNativeQueue ///< [out] a pointer to the native handle of the queue.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime queue object from native queue handle.
///
/// @details
///     - Creates runtime queue handle from native driver queue handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phQueue`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urQueueCreateWithNativeHandle(
    ur_native_handle_t
        hNativeQueue, ///< [in][nocheck] the native handle of the queue.
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice, ///< [in][optional] handle of the device object
    const ur_queue_native_properties_t *
        pProperties, ///< [in][optional] pointer to native queue properties struct
    ur_queue_handle_t
        *phQueue ///< [out] pointer to the handle of the queue object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Blocks until all previously issued commands to the command queue are
///        finished.
///
/// @details
///     - Blocks until all previously issued commands to the command queue are
///       issued and completed.
///     - ::urQueueFinish does not return until all enqueued commands have been
///       processed and finished.
///     - ::urQueueFinish acts as a synchronization point.
///
/// @remarks
///   _Analogues_
///     - **clFinish**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urQueueFinish(
    ur_queue_handle_t hQueue ///< [in] handle of the queue to be finished.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Issues all previously enqueued commands in a command queue to the
///        device.
///
/// @details
///     - Guarantees that all enqueued commands will be issued to the
///       appropriate device.
///     - There is no guarantee that they will be completed after ::urQueueFlush
///       returns.
///
/// @remarks
///   _Analogues_
///     - **clFlush**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urQueueFlush(
    ur_queue_handle_t hQueue ///< [in] handle of the queue to be flushed.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get event object information
///
/// @remarks
///   _Analogues_
///     - **clGetEventInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EVENT_INFO_REFERENCE_COUNT < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urEventGetInfo(
    ur_event_handle_t hEvent, ///< [in] handle of the event object
    ur_event_info_t propName, ///< [in] the name of the event property to query
    size_t propSize, ///< [in] size in bytes of the event property value
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the event
                    ///< property
    size_t *pPropSizeRet ///< [out][optional] bytes returned in event property
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get profiling information for the command associated with an event
///        object
///
/// @remarks
///   _Analogues_
///     - **clGetEventProfilingInfo**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_PROFILING_INFO_COMMAND_COMPLETE < propName`
///     - ::UR_RESULT_ERROR_PROFILING_INFO_NOT_AVAILABLE
///         + If `hEvent`s associated queue was not created with `UR_QUEUE_FLAG_PROFILING_ENABLE`.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pPropValue && propSize == 0`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urEventGetProfilingInfo(
    ur_event_handle_t hEvent, ///< [in] handle of the event object
    ur_profiling_info_t
        propName,    ///< [in] the name of the profiling property to query
    size_t propSize, ///< [in] size in bytes of the profiling property value
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the profiling
                    ///< property
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes returned in
                     ///< propValue
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Wait for a list of events to finish.
///
/// @remarks
///   _Analogues_
///     - **clWaitForEvent**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phEventWaitList`
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `numEvents == 0`
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEventWait(
    uint32_t numEvents, ///< [in] number of events in the event list
    const ur_event_handle_t *
        phEventWaitList ///< [in][range(0, numEvents)] pointer to a list of events to wait for
                        ///< completion
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a reference to an event handle. Increment the event object's
///        reference count.
///
/// @remarks
///   _Analogues_
///     - **clRetainEvent**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urEventRetain(
    ur_event_handle_t hEvent ///< [in][retain] handle of the event object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the event object's reference count and delete the event
///        object if the reference count becomes zero.
///
/// @remarks
///   _Analogues_
///     - **clReleaseEvent**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urEventRelease(
    ur_event_handle_t hEvent ///< [in][release] handle of the event object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Return platform native event handle.
///
/// @details
///     - Retrieved native handle can be used for direct interaction with the
///       native platform driver.
///     - Use interoperability platform extensions to convert native handle to
///       native type.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phNativeEvent`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urEventGetNativeHandle(
    ur_event_handle_t hEvent, ///< [in] handle of the event.
    ur_native_handle_t
        *phNativeEvent ///< [out] a pointer to the native handle of the event.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create runtime event object from native event handle.
///
/// @details
///     - Creates runtime event handle from native driver event handle.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phEvent`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the adapter has no underlying equivalent handle.
ur_result_t UR_APICALL urEventCreateWithNativeHandle(
    ur_native_handle_t
        hNativeEvent, ///< [in][nocheck] the native handle of the event.
    ur_context_handle_t hContext, ///< [in] handle of the context object
    const ur_event_native_properties_t *
        pProperties, ///< [in][optional] pointer to native event properties struct
    ur_event_handle_t
        *phEvent ///< [out] pointer to the handle of the event object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Register a user callback function for a specific command execution
///        status.
///
/// @details
///     - The registered callback function will be called when the execution
///       status of command associated with event changes to an execution status
///       equal to or past the status specified by command_exec_status.
///     - `execStatus` must not be `UR_EXECUTION_INFO_QUEUED` as this is the
///       initial state of all events.
///     - The application may call this function from simultaneous threads for
///       the same context.
///     - The implementation of this function should be thread-safe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hEvent`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXECUTION_INFO_QUEUED < execStatus`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pfnNotify`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + `execStatus == UR_EXECUTION_INFO_QUEUED`
ur_result_t UR_APICALL urEventSetCallback(
    ur_event_handle_t hEvent,       ///< [in] handle of the event object
    ur_execution_info_t execStatus, ///< [in] execution status of the event
    ur_event_callback_t pfnNotify,  ///< [in] execution status of the event
    void *
        pUserData ///< [in][out][optional] pointer to data to be passed to callback.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to execute a kernel
///
/// @remarks
///   _Analogues_
///     - **clEnqueueNDRangeKernel**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalWorkOffset`
///         + `NULL == pGlobalWorkSize`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_WORK_DIMENSION
///     - ::UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGS - "The kernel argument values have not been specified."
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueKernelLaunch(
    ur_queue_handle_t hQueue,   ///< [in] handle of the queue object
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t
        workDim, ///< [in] number of dimensions, from 1 to 3, to specify the global and
                 ///< work-group work-items
    const size_t *
        pGlobalWorkOffset, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< offset used to calculate the global ID of a work-item
    const size_t *
        pGlobalWorkSize, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< number of global work-items in workDim that will execute the kernel
    ///< function
    const size_t *
        pLocalWorkSize, ///< [in][optional] pointer to an array of workDim unsigned values that
    ///< specify the number of local work-items forming a work-group that will
    ///< execute the kernel function.
    ///< If nullptr, the runtime implementation will choose the work-group size.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command which waits a list of events to complete before it
///        completes
///
/// @details
///     - If the event list is empty, it waits for all previously enqueued
///       commands to complete.
///     - It returns an event which can be waited on.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueMarkerWithWaitList**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueEventsWait(
    ur_queue_handle_t hQueue,     ///< [in] handle of the queue object
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a barrier command which waits a list of events to complete
///        before it completes
///
/// @details
///     - If the event list is empty, it waits for all previously enqueued
///       commands to complete.
///     - It blocks command execution - any following commands enqueued after it
///       do not execute until it completes.
///     - It returns an event which can be waited on.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueBarrierWithWaitList**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueEventsWaitWithBarrier(
    ur_queue_handle_t hQueue,     ///< [in] handle of the queue object
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to read from a buffer object to host memory
///
/// @details
///     - Input parameter blockingRead indicates if the read is blocking or
///       non-blocking.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueReadBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `offset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferRead(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(offset, size)] handle of the buffer object
    bool blockingRead, ///< [in] indicates blocking (true), non-blocking (false)
    size_t offset,     ///< [in] offset in bytes in the buffer object
    size_t size,       ///< [in] size in bytes of data being read
    void *pDst, ///< [in] pointer to host memory where data is to be read into
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to write into a buffer object from host memory
///
/// @details
///     - Input parameter blockingWrite indicates if the write is blocking or
///       non-blocking.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueWriteBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `offset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferWrite(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(offset, size)] handle of the buffer object
    bool
        blockingWrite, ///< [in] indicates blocking (true), non-blocking (false)
    size_t offset,     ///< [in] offset in bytes in the buffer object
    size_t size,       ///< [in] size in bytes of data being written
    const void
        *pSrc, ///< [in] pointer to host memory where data is to be written from
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to read a 2D or 3D rectangular region from a buffer
///        object to host memory
///
/// @details
///     - Input parameter blockingRead indicates if the read is blocking or
///       non-blocking.
///     - The buffer and host 2D or 3D rectangular regions can have different
///       shapes.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueReadBufferRect**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.width == 0`
///         + `bufferRowPitch != 0 && bufferRowPitch < region.width`
///         + `hostRowPitch != 0 && hostRowPitch < region.width`
///         + `bufferSlicePitch != 0 && bufferSlicePitch < region.height * (bufferRowPitch != 0 ? bufferRowPitch : region.width)`
///         + `bufferSlicePitch != 0 && bufferSlicePitch % (bufferRowPitch != 0 ? bufferRowPitch : region.width) != 0`
///         + `hostSlicePitch != 0 && hostSlicePitch < region.height * (hostRowPitch != 0 ? hostRowPitch : region.width)`
///         + `hostSlicePitch != 0 && hostSlicePitch % (hostRowPitch != 0 ? hostRowPitch : region.width) != 0`
///         + If the combination of `bufferOrigin`, `region`, `bufferRowPitch`, and `bufferSlicePitch` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferReadRect(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(bufferOrigin, region)] handle of the buffer object
    bool blockingRead, ///< [in] indicates blocking (true), non-blocking (false)
    ur_rect_offset_t bufferOrigin, ///< [in] 3D offset in the buffer
    ur_rect_offset_t hostOrigin,   ///< [in] 3D offset in the host region
    ur_rect_region_t
        region, ///< [in] 3D rectangular region descriptor: width, height, depth
    size_t
        bufferRowPitch, ///< [in] length of each row in bytes in the buffer object
    size_t
        bufferSlicePitch, ///< [in] length of each 2D slice in bytes in the buffer object being read
    size_t
        hostRowPitch, ///< [in] length of each row in bytes in the host memory region pointed by
                      ///< dst
    size_t
        hostSlicePitch, ///< [in] length of each 2D slice in bytes in the host memory region
                        ///< pointed by dst
    void *pDst, ///< [in] pointer to host memory where data is to be read into
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to write a 2D or 3D rectangular region in a buffer
///        object from host memory
///
/// @details
///     - Input parameter blockingWrite indicates if the write is blocking or
///       non-blocking.
///     - The buffer and host 2D or 3D rectangular regions can have different
///       shapes.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueWriteBufferRect**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.width == 0`
///         + `bufferRowPitch != 0 && bufferRowPitch < region.width`
///         + `hostRowPitch != 0 && hostRowPitch < region.width`
///         + `bufferSlicePitch != 0 && bufferSlicePitch < region.height * (bufferRowPitch != 0 ? bufferRowPitch : region.width)`
///         + `bufferSlicePitch != 0 && bufferSlicePitch % (bufferRowPitch != 0 ? bufferRowPitch : region.width) != 0`
///         + `hostSlicePitch != 0 && hostSlicePitch < region.height * (hostRowPitch != 0 ? hostRowPitch : region.width)`
///         + `hostSlicePitch != 0 && hostSlicePitch % (hostRowPitch != 0 ? hostRowPitch : region.width) != 0`
///         + If the combination of `bufferOrigin`, `region`, `bufferRowPitch`, and `bufferSlicePitch` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferWriteRect(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(bufferOrigin, region)] handle of the buffer object
    bool
        blockingWrite, ///< [in] indicates blocking (true), non-blocking (false)
    ur_rect_offset_t bufferOrigin, ///< [in] 3D offset in the buffer
    ur_rect_offset_t hostOrigin,   ///< [in] 3D offset in the host region
    ur_rect_region_t
        region, ///< [in] 3D rectangular region descriptor: width, height, depth
    size_t
        bufferRowPitch, ///< [in] length of each row in bytes in the buffer object
    size_t
        bufferSlicePitch, ///< [in] length of each 2D slice in bytes in the buffer object being
                          ///< written
    size_t
        hostRowPitch, ///< [in] length of each row in bytes in the host memory region pointed by
                      ///< src
    size_t
        hostSlicePitch, ///< [in] length of each 2D slice in bytes in the host memory region
                        ///< pointed by src
    void
        *pSrc, ///< [in] pointer to host memory where data is to be written from
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] points to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to copy from a buffer object to another
///
/// @remarks
///   _Analogues_
///     - **clEnqueueCopyBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBufferSrc`
///         + `NULL == hBufferDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `srcOffset + size` results in an out-of-bounds access.
///         + If `dstOffset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferCopy(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBufferSrc, ///< [in][bounds(srcOffset, size)] handle of the src buffer object
    ur_mem_handle_t
        hBufferDst, ///< [in][bounds(dstOffset, size)] handle of the dest buffer object
    size_t srcOffset, ///< [in] offset into hBufferSrc to begin copying from
    size_t dstOffset, ///< [in] offset info hBufferDst to begin copying into
    size_t size,      ///< [in] size in bytes of data being copied
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to copy a 2D or 3D rectangular region from one
///        buffer object to another
///
/// @remarks
///   _Analogues_
///     - **clEnqueueCopyBufferRect**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBufferSrc`
///         + `NULL == hBufferDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.depth == 0`
///         + `srcRowPitch != 0 && srcRowPitch < region.width`
///         + `dstRowPitch != 0 && dstRowPitch < region.width`
///         + `srcSlicePitch != 0 && srcSlicePitch < region.height * (srcRowPitch != 0 ? srcRowPitch : region.width)`
///         + `srcSlicePitch != 0 && srcSlicePitch % (srcRowPitch != 0 ? srcRowPitch : region.width) != 0`
///         + `dstSlicePitch != 0 && dstSlicePitch < region.height * (dstRowPitch != 0 ? dstRowPitch : region.width)`
///         + `dstSlicePitch != 0 && dstSlicePitch % (dstRowPitch != 0 ? dstRowPitch : region.width) != 0`
///         + If the combination of `srcOrigin`, `region`, `srcRowPitch`, and `srcSlicePitch` results in an out-of-bounds access.
///         + If the combination of `dstOrigin`, `region`, `dstRowPitch`, and `dstSlicePitch` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferCopyRect(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBufferSrc, ///< [in][bounds(srcOrigin, region)] handle of the source buffer object
    ur_mem_handle_t
        hBufferDst, ///< [in][bounds(dstOrigin, region)] handle of the dest buffer object
    ur_rect_offset_t srcOrigin, ///< [in] 3D offset in the source buffer
    ur_rect_offset_t dstOrigin, ///< [in] 3D offset in the destination buffer
    ur_rect_region_t
        region, ///< [in] source 3D rectangular region descriptor: width, height, depth
    size_t
        srcRowPitch, ///< [in] length of each row in bytes in the source buffer object
    size_t
        srcSlicePitch, ///< [in] length of each 2D slice in bytes in the source buffer object
    size_t
        dstRowPitch, ///< [in] length of each row in bytes in the destination buffer object
    size_t
        dstSlicePitch, ///< [in] length of each 2D slice in bytes in the destination buffer object
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to fill a buffer object with a pattern of a given
///        size
///
/// @remarks
///   _Analogues_
///     - **clEnqueueFillBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pPattern`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `patternSize == 0 || size == 0`
///         + `patternSize > size`
///         + `(patternSize & (patternSize - 1)) != 0`
///         + `size % patternSize != 0`
///         + `offset % patternSize != 0`
///         + If `offset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferFill(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(offset, size)] handle of the buffer object
    const void *pPattern, ///< [in] pointer to the fill pattern
    size_t patternSize,   ///< [in] size in bytes of the pattern
    size_t offset,        ///< [in] offset into the buffer
    size_t size, ///< [in] fill size in bytes, must be a multiple of patternSize
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to read from an image or image array object to host
///        memory
///
/// @details
///     - Input parameter blockingRead indicates if the read is blocking or
///       non-blocking.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueReadImage**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hImage`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.depth == 0`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemImageRead(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hImage, ///< [in][bounds(origin, region)] handle of the image object
    bool blockingRead, ///< [in] indicates blocking (true), non-blocking (false)
    ur_rect_offset_t
        origin, ///< [in] defines the (x,y,z) offset in pixels in the 1D, 2D, or 3D image
    ur_rect_region_t
        region, ///< [in] defines the (width, height, depth) in pixels of the 1D, 2D, or 3D
                ///< image
    size_t rowPitch,   ///< [in] length of each row in bytes
    size_t slicePitch, ///< [in] length of each 2D slice of the 3D image
    void *pDst, ///< [in] pointer to host memory where image is to be read into
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to write an image or image array object from host
///        memory
///
/// @details
///     - Input parameter blockingWrite indicates if the write is blocking or
///       non-blocking.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueWriteImage**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hImage`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.depth == 0`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemImageWrite(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hImage, ///< [in][bounds(origin, region)] handle of the image object
    bool
        blockingWrite, ///< [in] indicates blocking (true), non-blocking (false)
    ur_rect_offset_t
        origin, ///< [in] defines the (x,y,z) offset in pixels in the 1D, 2D, or 3D image
    ur_rect_region_t
        region, ///< [in] defines the (width, height, depth) in pixels of the 1D, 2D, or 3D
                ///< image
    size_t rowPitch,   ///< [in] length of each row in bytes
    size_t slicePitch, ///< [in] length of each 2D slice of the 3D image
    void *pSrc, ///< [in] pointer to host memory where image is to be read into
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to copy from an image object to another
///
/// @remarks
///   _Analogues_
///     - **clEnqueueCopyImage**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hImageSrc`
///         + `NULL == hImageDst`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `region.width == 0 || region.height == 0 || region.depth == 0`
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemImageCopy(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hImageSrc, ///< [in][bounds(srcOrigin, region)] handle of the src image object
    ur_mem_handle_t
        hImageDst, ///< [in][bounds(dstOrigin, region)] handle of the dest image object
    ur_rect_offset_t
        srcOrigin, ///< [in] defines the (x,y,z) offset in pixels in the source 1D, 2D, or 3D
                   ///< image
    ur_rect_offset_t
        dstOrigin, ///< [in] defines the (x,y,z) offset in pixels in the destination 1D, 2D,
                   ///< or 3D image
    ur_rect_region_t
        region, ///< [in] defines the (width, height, depth) in pixels of the 1D, 2D, or 3D
                ///< image
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to map a region of the buffer object into the host
///        address space and return a pointer to the mapped region
///
/// @details
///     - Input parameter blockingMap indicates if the map is blocking or
///       non-blocking.
///     - Currently, no direct support in Level Zero. Implemented as a shared
///       allocation followed by copying on discrete GPU
///     - TODO: add a driver function in Level Zero?
///
/// @remarks
///   _Analogues_
///     - **clEnqueueMapBuffer**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_MAP_FLAGS_MASK & mapFlags`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppRetMap`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `offset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemBufferMap(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hBuffer, ///< [in][bounds(offset, size)] handle of the buffer object
    bool blockingMap, ///< [in] indicates blocking (true), non-blocking (false)
    ur_map_flags_t mapFlags, ///< [in] flags for read, write, readwrite mapping
    size_t offset, ///< [in] offset in bytes of the buffer region being mapped
    size_t size,   ///< [in] size in bytes of the buffer region being mapped
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
    void **ppRetMap ///< [out] return mapped pointer.  TODO: move it before
                    ///< numEventsInWaitList?
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to unmap a previously mapped region of a memory
///        object
///
/// @remarks
///   _Analogues_
///     - **clEnqueueUnmapMemObject**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hMem`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMappedPtr`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueMemUnmap(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_mem_handle_t
        hMem,         ///< [in] handle of the memory (buffer or image) object
    void *pMappedPtr, ///< [in] mapped host address
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to fill USM memory.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///         + `NULL == pPattern`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `patternSize == 0 || size == 0`
///         + `patternSize > size`
///         + `size % patternSize != 0`
///         + If `size` is higher than the allocation size of `ptr`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueUSMFill(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    void *pMem, ///< [in][bounds(0, size)] pointer to USM memory object
    size_t
        patternSize, ///< [in] the size in bytes of the pattern. Must be a power of 2 and less
                     ///< than or equal to width.
    const void
        *pPattern, ///< [in] pointer with the bytes of the pattern to set.
    size_t
        size, ///< [in] size in bytes to be set. Must be a multiple of patternSize.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to copy USM memory
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pSrc` or `pDst`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueUSMMemcpy(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    bool blocking,            ///< [in] blocking or non-blocking copy
    void *
        pDst, ///< [in][bounds(0, size)] pointer to the destination USM memory object
    const void *
        pSrc, ///< [in][bounds(0, size)] pointer to the source USM memory object
    size_t size,                  ///< [in] size in bytes to be copied
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to prefetch USM memory
///
/// @details
///     - Prefetching may not be supported for all devices or allocation types.
///       If memory prefetching is not supported, the prefetch hint will be
///       ignored.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_MIGRATION_FLAGS_MASK & flags`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pMem`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueUSMPrefetch(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    const void
        *pMem,   ///< [in][bounds(0, size)] pointer to the USM memory object
    size_t size, ///< [in] size in bytes to be fetched
    ur_usm_migration_flags_t flags, ///< [in] USM prefetch flags
    uint32_t numEventsInWaitList,   ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that this
    ///< command does not wait on any event to complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to set USM memory advice
///
/// @details
///     - Not all memory advice hints may be supported for all devices or
///       allocation types. If a memory advice hint is not supported, it will be
///       ignored.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_ADVICE_FLAGS_MASK & advice`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pMem`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueUSMAdvise(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    const void
        *pMem,   ///< [in][bounds(0, size)] pointer to the USM memory object
    size_t size, ///< [in] size in bytes to be advised
    ur_usm_advice_flags_t advice, ///< [in] USM memory advice
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
                ///< command instance.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to fill 2D USM memory.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///         + `NULL == pPattern`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `pitch == 0`
///         + `pitch < width`
///         + `patternSize == 0`
///         + `patternSize > width * height`
///         + `patternSize != 0 && ((patternSize & (patternSize - 1)) != 0)`
///         + `width == 0`
///         + `height == 0`
///         + `width * height % patternSize != 0`
///         + If `pitch * height` is higher than the allocation size of `pMem`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urEnqueueUSMFill2D(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue to submit to.
    void *
        pMem, ///< [in][bounds(0, pitch * height)] pointer to memory to be filled.
    size_t
        pitch, ///< [in] the total width of the destination memory including padding.
    size_t
        patternSize, ///< [in] the size in bytes of the pattern. Must be a power of 2 and less
                     ///< than or equal to width.
    const void
        *pPattern, ///< [in] pointer with the bytes of the pattern to set.
    size_t
        width, ///< [in] the width in bytes of each row to fill. Must be a multiple of
               ///< patternSize.
    size_t height,                ///< [in] the height of the columns to fill.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to copy 2D USM memory.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `srcPitch == 0`
///         + `dstPitch == 0`
///         + `srcPitch < width`
///         + `dstPitch < width`
///         + `height == 0`
///         + If `srcPitch * height` is higher than the allocation size of `pSrc`
///         + If `dstPitch * height` is higher than the allocation size of `pDst`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
ur_result_t UR_APICALL urEnqueueUSMMemcpy2D(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue to submit to.
    bool blocking, ///< [in] indicates if this operation should block the host.
    void *
        pDst, ///< [in][bounds(0, dstPitch * height)] pointer to memory where data will
              ///< be copied.
    size_t
        dstPitch, ///< [in] the total width of the source memory including padding.
    const void *
        pSrc, ///< [in][bounds(0, srcPitch * height)] pointer to memory to be copied.
    size_t
        srcPitch, ///< [in] the total width of the source memory including padding.
    size_t width,  ///< [in] the width in bytes of each row to be copied.
    size_t height, ///< [in] the height of columns to be copied.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to write data from the host to device global
///        variable.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == name`
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
ur_result_t UR_APICALL urEnqueueDeviceGlobalVariableWrite(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue to submit to.
    ur_program_handle_t
        hProgram, ///< [in] handle of the program containing the device global variable.
    const char
        *name, ///< [in] the unique identifier for the device global variable.
    bool blockingWrite, ///< [in] indicates if this operation should block.
    size_t count,       ///< [in] the number of bytes to copy.
    size_t
        offset, ///< [in] the byte offset into the device global variable to start copying.
    const void *pSrc, ///< [in] pointer to where the data must be copied from.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to read data from a device global variable to the
///        host.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == name`
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
ur_result_t UR_APICALL urEnqueueDeviceGlobalVariableRead(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue to submit to.
    ur_program_handle_t
        hProgram, ///< [in] handle of the program containing the device global variable.
    const char
        *name, ///< [in] the unique identifier for the device global variable.
    bool blockingRead, ///< [in] indicates if this operation should block.
    size_t count,      ///< [in] the number of bytes to copy.
    size_t
        offset, ///< [in] the byte offset into the device global variable to start copying.
    void *pDst, ///< [in] pointer to where the data must be copied to.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to read from a pipe to the host.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pipe_symbol`
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
ur_result_t UR_APICALL urEnqueueReadHostPipe(
    ur_queue_handle_t
        hQueue, ///< [in] a valid host command-queue in which the read command
    ///< will be queued. hQueue and hProgram must be created with the same
    ///< UR context.
    ur_program_handle_t
        hProgram, ///< [in] a program object with a successfully built executable.
    const char *
        pipe_symbol, ///< [in] the name of the program scope pipe global variable.
    bool
        blocking, ///< [in] indicate if the read operation is blocking or non-blocking.
    void *
        pDst, ///< [in] a pointer to buffer in host memory that will hold resulting data
              ///< from pipe.
    size_t size, ///< [in] size of the memory region to read, in bytes.
    uint32_t numEventsInWaitList, ///< [in] number of events in the wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the host pipe read.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] returns an event object that identifies this read command
    ///< and can be used to query or queue a wait for this command to complete.
    ///< If phEventWaitList and phEvent are not NULL, phEvent must not refer to
    ///< an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to write data from the host to a pipe.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pipe_symbol`
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
ur_result_t UR_APICALL urEnqueueWriteHostPipe(
    ur_queue_handle_t
        hQueue, ///< [in] a valid host command-queue in which the write command
    ///< will be queued. hQueue and hProgram must be created with the same
    ///< UR context.
    ur_program_handle_t
        hProgram, ///< [in] a program object with a successfully built executable.
    const char *
        pipe_symbol, ///< [in] the name of the program scope pipe global variable.
    bool
        blocking, ///< [in] indicate if the read and write operations are blocking or
                  ///< non-blocking.
    void *
        pSrc, ///< [in] a pointer to buffer in host memory that holds data to be written
              ///< to the host pipe.
    size_t size, ///< [in] size of the memory region to read or write, in bytes.
    uint32_t numEventsInWaitList, ///< [in] number of events in the wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the host pipe write.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] returns an event object that identifies this write command
    ///< and can be used to query or queue a wait for this command to complete.
    ///< If phEventWaitList and phEvent are not NULL, phEvent must not refer to
    ///< an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief USM allocate pitched memory
///
/// @details
///     - This function must support memory pooling.
///     - If pUSMDesc is not NULL and pUSMDesc->pool is not NULL the allocation
///       will be served from a specified memory pool.
///     - Otherwise, the behavior is implementation-defined.
///     - Allocations served from different memory pools must be isolated and
///       must not reside on the same page.
///     - Any flags/hints passed through pUSMDesc only affect the single
///       allocation.
///     - See also ::ur_usm_host_desc_t.
///     - See also ::ur_usm_device_desc_t.
///
/// @remarks
///   _Analogues_
///     - **cuMemAllocPitch**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pUSMDesc && ::UR_USM_ADVICE_FLAGS_MASK & pUSMDesc->hints`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppMem`
///         + `NULL == pResultPitch`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `pUSMDesc && pUSMDesc->align != 0 && ((pUSMDesc->align & (pUSMDesc->align-1)) != 0)`
///         + If `align` is greater that the size of the largest data type supported by `hDevice`.
///     - ::UR_RESULT_ERROR_INVALID_USM_SIZE
///         + `widthInBytes == 0`
///         + `size` is greater than ::UR_DEVICE_INFO_MAX_MEM_ALLOC_SIZE.
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If `UR_DEVICE_INFO_USM_SINGLE_SHARED_SUPPORT` and `UR_DEVICE_INFO_USM_CROSS_SHARED_SUPPORT` are both false.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urUSMPitchedAllocExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_usm_desc_t *
        pUSMDesc, ///< [in][optional] Pointer to USM memory allocation descriptor.
    ur_usm_pool_handle_t
        pool, ///< [in][optional] Pointer to a pool created using urUSMPoolCreate
    size_t
        widthInBytes, ///< [in] width in bytes of the USM memory object to be allocated
    size_t height, ///< [in] height of the USM memory object to be allocated
    size_t
        elementSizeBytes, ///< [in] size in bytes of an element in the allocation
    void **ppMem,         ///< [out] pointer to USM shared memory object
    size_t *pResultPitch  ///< [out] pitch of the allocation
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Destroy bindless unsampled image handles
///
/// @remarks
///   _Analogues_
///     - **cuSurfObjectDestroy**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesUnsampledImageHandleDestroyExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_native_handle_t
        hImage ///< [in][release] pointer to handle of image object to destroy
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Destroy bindless sampled image handles
///
/// @remarks
///   _Analogues_
///     - **cuTexObjectDestroy**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesSampledImageHandleDestroyExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_native_handle_t
        hImage ///< [in][release] pointer to handle of image object to destroy
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Allocate memory for bindless images
///
/// @remarks
///   _Analogues_
///     - **cuArray3DCreate**
///     - **cuMipmappedArrayCreate**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phImageMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pImageDesc->type`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
ur_result_t UR_APICALL urBindlessImagesImageAllocateExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description
    ur_exp_image_mem_native_handle_t
        *phImageMem ///< [out] pointer to handle of image memory allocated
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Free memory for bindless images
///
/// @remarks
///   _Analogues_
///     - **cuArrayDestroy**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesImageFreeExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_mem_native_handle_t
        hImageMem ///< [in][release] handle of image memory to be freed
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a bindless unsampled image handle
///
/// @remarks
///   _Analogues_
///     - **cuSurfObjectCreate**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phImage`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pImageDesc->type`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
ur_result_t UR_APICALL urBindlessImagesUnsampledImageCreateExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_mem_native_handle_t
        hImageMem, ///< [in] handle to memory from which to create the image
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description
    ur_exp_image_native_handle_t
        *phImage ///< [out] pointer to handle of image object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a bindless sampled image handle
///
/// @remarks
///   _Analogues_
///     - **cuTexObjectCreate**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///         + `NULL == hSampler`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phImage`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pImageDesc->type`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_SAMPLER
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
ur_result_t UR_APICALL urBindlessImagesSampledImageCreateExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_mem_native_handle_t
        hImageMem, ///< [in] handle to memory from which to create the image
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description
    ur_sampler_handle_t hSampler,      ///< [in] sampler to be used
    ur_exp_image_native_handle_t
        *phImage ///< [out] pointer to handle of image object created
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Copy image data Host to Device, Device to Host, or Device to Device
///
/// @remarks
///   _Analogues_
///     - **cuMemcpyHtoAAsync**
///     - **cuMemcpyAtoHAsync**
///     - **cuMemcpy2DAsync**
///     - **cuMemcpy3DAsync**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///         + `NULL == pDst`
///         + `NULL == pSrcImageDesc`
///         + `NULL == pDstImageDesc`
///         + `NULL == pSrcImageFormat`
///         + `NULL == pDstImageFormat`
///         + `NULL == pCopyRegion`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_IMAGE_COPY_FLAGS_MASK & imageCopyFlags`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pSrcImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pSrcImageDesc->type`
///         + `pDstImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pDstImageDesc->type`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
ur_result_t UR_APICALL urBindlessImagesImageCopyExp(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    const void *pSrc,         ///< [in] location the data will be copied from
    void *pDst,               ///< [in] location the data will be copied to
    const ur_image_desc_t *pSrcImageDesc, ///< [in] pointer to image description
    const ur_image_desc_t *pDstImageDesc, ///< [in] pointer to image description
    const ur_image_format_t
        *pSrcImageFormat, ///< [in] pointer to image format specification
    const ur_image_format_t
        *pDstImageFormat, ///< [in] pointer to image format specification
    ur_exp_image_copy_region_t *
        pCopyRegion, ///< [in] Pointer to structure describing the (sub-)regions of source and
                     ///< destination images
    ur_exp_image_copy_flags_t
        imageCopyFlags, ///< [in] flags describing copy direction e.g. H2D or D2H
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query an image memory handle for specific properties
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_IMAGE_INFO_DEPTH < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urBindlessImagesImageGetInfoExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_exp_image_mem_native_handle_t
        hImageMem,            ///< [in] handle to the image memory
    ur_image_info_t propName, ///< [in] queried info name
    void *pPropValue,         ///< [out][optional] returned query value
    size_t *pPropSizeRet      ///< [out][optional] returned query value size
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieve individual image from mipmap
///
/// @remarks
///   _Analogues_
///     - **cuMipmappedArrayGetLevel**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phImageMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesMipmapGetLevelExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_mem_native_handle_t
        hImageMem,        ///< [in] memory handle to the mipmap image
    uint32_t mipmapLevel, ///< [in] requested level of the mipmap
    ur_exp_image_mem_native_handle_t
        *phImageMem ///< [out] returning memory handle to the individual image
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Free mipmap memory for bindless images
///
/// @remarks
///   _Analogues_
///     - **cuMipmappedArrayDestroy**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesMipmapFreeExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_image_mem_native_handle_t
        hMem ///< [in][release] handle of image memory to be freed
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Import external memory
///
/// @remarks
///   _Analogues_
///     - **cuImportExternalMemory**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_EXTERNAL_MEM_TYPE_WIN32_NT_DX12_RESOURCE < memHandleType`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pExternalMemDesc`
///         + `NULL == phExternalMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
ur_result_t UR_APICALL urBindlessImagesImportExternalMemoryExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    size_t size,                  ///< [in] size of the external memory
    ur_exp_external_mem_type_t
        memHandleType, ///< [in] type of external memory handle
    ur_exp_external_mem_desc_t
        *pExternalMemDesc, ///< [in] the external memory descriptor
    ur_exp_external_mem_handle_t
        *phExternalMem ///< [out] external memory handle to the external memory
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Map an external memory handle to an image memory handle
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///         + `NULL == hExternalMem`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pImageFormat`
///         + `NULL == pImageDesc`
///         + `NULL == phImageMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_FORMAT_DESCRIPTOR
///         + `pImageDesc && UR_MEM_TYPE_IMAGE_CUBEMAP_EXP < pImageDesc->type`
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urBindlessImagesMapExternalArrayExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    const ur_image_format_t
        *pImageFormat, ///< [in] pointer to image format specification
    const ur_image_desc_t *pImageDesc, ///< [in] pointer to image description
    ur_exp_external_mem_handle_t
        hExternalMem, ///< [in] external memory handle to the external memory
    ur_exp_image_mem_native_handle_t *
        phImageMem ///< [out] image memory handle to the externally allocated memory
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Map an external memory handle to a device memory region described by
///        void*
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///         + `NULL == hExternalMem`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == ppRetMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_INVALID_IMAGE_SIZE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urBindlessImagesMapExternalLinearMemoryExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    uint64_t offset,              ///< [in] offset into memory region to map
    uint64_t size,                ///< [in] size of memory region to map
    ur_exp_external_mem_handle_t
        hExternalMem, ///< [in] external memory handle to the external memory
    void **ppRetMem   ///< [out] pointer of the externally allocated memory
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release external memory
///
/// @remarks
///   _Analogues_
///     - **cuDestroyExternalMemory**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///         + `NULL == hExternalMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesReleaseExternalMemoryExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_external_mem_handle_t
        hExternalMem ///< [in][release] handle of external memory to be destroyed
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Import an external semaphore
///
/// @remarks
///   _Analogues_
///     - **cuImportExternalSemaphore**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_EXTERNAL_SEMAPHORE_TYPE_WIN32_NT_DX12_FENCE < semHandleType`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pExternalSemaphoreDesc`
///         + `NULL == phExternalSemaphore`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesImportExternalSemaphoreExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_external_semaphore_type_t
        semHandleType, ///< [in] type of external memory handle
    ur_exp_external_semaphore_desc_t
        *pExternalSemaphoreDesc, ///< [in] the external semaphore descriptor
    ur_exp_external_semaphore_handle_t *
        phExternalSemaphore ///< [out] external semaphore handle to the external semaphore
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release the external semaphore
///
/// @remarks
///   _Analogues_
///     - **cuDestroyExternalSemaphore**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///         + `NULL == hExternalSemaphore`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesReleaseExternalSemaphoreExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    ur_device_handle_t hDevice,   ///< [in] handle of the device object
    ur_exp_external_semaphore_handle_t
        hExternalSemaphore ///< [in][release] handle of external semaphore to be destroyed
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Instruct the queue with a non-blocking wait on an external semaphore
///
/// @remarks
///   _Analogues_
///     - **cuWaitExternalSemaphoresAsync**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hSemaphore`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesWaitExternalSemaphoreExp(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_exp_external_semaphore_handle_t
        hSemaphore, ///< [in] external semaphore handle
    bool
        hasWaitValue, ///< [in] indicates whether the samephore is capable and should wait on a
                      ///< certain value.
    ///< Otherwise the semaphore is treated like a binary state, and
    ///< `waitValue` is ignored.
    uint64_t waitValue,           ///< [in] the value to be waited on
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Instruct the queue to signal the external semaphore handle once all
///        previous commands have completed execution
///
/// @remarks
///   _Analogues_
///     - **cuSignalExternalSemaphoresAsync**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hSemaphore`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
ur_result_t UR_APICALL urBindlessImagesSignalExternalSemaphoreExp(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_exp_external_semaphore_handle_t
        hSemaphore, ///< [in] external semaphore handle
    bool
        hasSignalValue, ///< [in] indicates whether the samephore is capable and should signal on a
                        ///< certain value.
    ///< Otherwise the semaphore is treated like a binary state, and
    ///< `signalValue` is ignored.
    uint64_t signalValue,         ///< [in] the value to be signalled
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Create a Command-Buffer object
///
/// @details
///     - Create a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_DEVICE
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If `pCommandBufferDesc->isUpdatable` is true and `hDevice` does not support UR_DEVICE_INFO_COMMAND_BUFFER_UPDATE_SUPPORT_EXP.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferCreateExp(
    ur_context_handle_t hContext, ///< [in] Handle of the context object.
    ur_device_handle_t hDevice,   ///< [in] Handle of the device object.
    const ur_exp_command_buffer_desc_t
        *pCommandBufferDesc, ///< [in][optional] command-buffer descriptor.
    ur_exp_command_buffer_handle_t
        *phCommandBuffer ///< [out] Pointer to command-Buffer handle.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Increment the command-buffer object's reference count.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferRetainExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer ///< [in][retain] Handle of the command-buffer object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the command-buffer object's reference count and delete the
///        command-buffer object if the reference count becomes zero.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferReleaseExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer ///< [in][release] Handle of the command-buffer object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Stop recording on a command-buffer object such that no more commands
///        can be appended and make it ready to enqueue.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferFinalizeExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer ///< [in] Handle of the command-buffer object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a kernel execution command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalWorkOffset`
///         + `NULL == pGlobalWorkSize`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
///     - ::UR_RESULT_ERROR_INVALID_WORK_DIMENSION
///     - ::UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + `phKernelAlternatives == NULL && numKernelAlternatives > 0`
///         + `phKernelAlternatives != NULL && numKernelAlternatives == 0`
///         + If `phKernelAlternatives` contains `hKernel`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_INVALID_OPERATION - "phCommand is not NULL and hCommandBuffer is not updatable."
ur_result_t UR_APICALL urCommandBufferAppendKernelLaunchExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,         ///< [in] Handle of the command-buffer object.
    ur_kernel_handle_t hKernel, ///< [in] Kernel to append.
    uint32_t workDim,           ///< [in] Dimension of the kernel execution.
    const size_t
        *pGlobalWorkOffset, ///< [in] Offset to use when executing kernel.
    const size_t *
        pGlobalWorkSize, ///< [in] Global work size to use when executing kernel.
    const size_t *
        pLocalWorkSize, ///< [in][optional] Local work size to use when executing kernel. If this
    ///< parameter is nullptr, then a local work size will be generated by the
    ///< implementation.
    uint32_t
        numKernelAlternatives, ///< [in] The number of kernel alternatives provided in
                               ///< phKernelAlternatives.
    ur_kernel_handle_t *
        phKernelAlternatives, ///< [in][optional][range(0, numKernelAlternatives)] List of kernel handles
    ///< that might be used to update the kernel in this
    ///< command after the command-buffer is finalized. The default kernel
    ///< `hKernel` is implicitly marked as an alternative. It's
    ///< invalid to specify it as part of this list.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t *
        phCommand ///< [out][optional] Handle to this command. Only available if the
                  ///< command-buffer is updatable.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a USM memcpy command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pSrc` or `pDst`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendUSMMemcpyExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer, ///< [in] Handle of the command-buffer object.
    void *pDst,         ///< [in] Location the data will be copied to.
    const void *pSrc,   ///< [in] The data to be copied.
    size_t size,        ///< [in] The number of bytes to copy.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a USM fill command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMemory`
///         + `NULL == pPattern`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `patternSize == 0 || size == 0`
///         + `patternSize > size`
///         + `size % patternSize != 0`
///         + If `size` is higher than the allocation size of `ptr`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendUSMFillExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,   ///< [in] handle of the command-buffer object.
    void *pMemory,        ///< [in] pointer to USM allocated memory to fill.
    const void *pPattern, ///< [in] pointer to the fill pattern.
    size_t patternSize,   ///< [in] size in bytes of the pattern.
    size_t
        size, ///< [in] fill size in bytes, must be a multiple of patternSize.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a memory copy command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hSrcMem`
///         + `NULL == hDstMem`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferCopyExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hSrcMem, ///< [in] The data to be copied.
    ur_mem_handle_t hDstMem, ///< [in] The location the data will be copied to.
    size_t srcOffset,        ///< [in] Offset into the source memory.
    size_t dstOffset,        ///< [in] Offset into the destination memory
    size_t size,             ///< [in] The number of bytes to be copied.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a memory write command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferWriteExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hBuffer, ///< [in] Handle of the buffer object.
    size_t offset,           ///< [in] Offset in bytes in the buffer object.
    size_t size,             ///< [in] Size in bytes of data being written.
    const void *
        pSrc, ///< [in] Pointer to host memory where data is to be written from.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a memory read command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferReadExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hBuffer, ///< [in] Handle of the buffer object.
    size_t offset,           ///< [in] Offset in bytes in the buffer object.
    size_t size,             ///< [in] Size in bytes of data being written.
    void *pDst, ///< [in] Pointer to host memory where data is to be written to.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a rectangular memory copy command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hSrcMem`
///         + `NULL == hDstMem`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferCopyRectExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hSrcMem, ///< [in] The data to be copied.
    ur_mem_handle_t hDstMem, ///< [in] The location the data will be copied to.
    ur_rect_offset_t
        srcOrigin, ///< [in] Origin for the region of data to be copied from the source.
    ur_rect_offset_t
        dstOrigin, ///< [in] Origin for the region of data to be copied to in the destination.
    ur_rect_region_t
        region, ///< [in] The extents describing the region to be copied.
    size_t srcRowPitch,   ///< [in] Row pitch of the source memory.
    size_t srcSlicePitch, ///< [in] Slice pitch of the source memory.
    size_t dstRowPitch,   ///< [in] Row pitch of the destination memory.
    size_t dstSlicePitch, ///< [in] Slice pitch of the destination memory.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a rectangular memory write command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pSrc`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferWriteRectExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hBuffer, ///< [in] Handle of the buffer object.
    ur_rect_offset_t bufferOffset, ///< [in] 3D offset in the buffer.
    ur_rect_offset_t hostOffset,   ///< [in] 3D offset in the host region.
    ur_rect_region_t
        region, ///< [in] 3D rectangular region descriptor: width, height, depth.
    size_t
        bufferRowPitch, ///< [in] Length of each row in bytes in the buffer object.
    size_t
        bufferSlicePitch, ///< [in] Length of each 2D slice in bytes in the buffer object being
                          ///< written.
    size_t
        hostRowPitch, ///< [in] Length of each row in bytes in the host memory region pointed to
                      ///< by pSrc.
    size_t
        hostSlicePitch, ///< [in] Length of each 2D slice in bytes in the host memory region
                        ///< pointed to by pSrc.
    void *
        pSrc, ///< [in] Pointer to host memory where data is to be written from.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a rectangular memory read command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pDst`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferReadRectExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] Handle of the command-buffer object.
    ur_mem_handle_t hBuffer, ///< [in] Handle of the buffer object.
    ur_rect_offset_t bufferOffset, ///< [in] 3D offset in the buffer.
    ur_rect_offset_t hostOffset,   ///< [in] 3D offset in the host region.
    ur_rect_region_t
        region, ///< [in] 3D rectangular region descriptor: width, height, depth.
    size_t
        bufferRowPitch, ///< [in] Length of each row in bytes in the buffer object.
    size_t
        bufferSlicePitch, ///< [in] Length of each 2D slice in bytes in the buffer object being read.
    size_t
        hostRowPitch, ///< [in] Length of each row in bytes in the host memory region pointed to
                      ///< by pDst.
    size_t
        hostSlicePitch, ///< [in] Length of each 2D slice in bytes in the host memory region
                        ///< pointed to by pDst.
    void *pDst, ///< [in] Pointer to host memory where data is to be read into.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] Sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a memory fill command to a command-buffer object.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pPattern`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + If `offset + size` results in an out-of-bounds access.
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendMemBufferFillExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,      ///< [in] handle of the command-buffer object.
    ur_mem_handle_t hBuffer, ///< [in] handle of the buffer object.
    const void *pPattern,    ///< [in] pointer to the fill pattern.
    size_t patternSize,      ///< [in] size in bytes of the pattern.
    size_t offset,           ///< [in] offset into the buffer.
    size_t
        size, ///< [in] fill size in bytes, must be a multiple of patternSize.
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a USM Prefetch command to a command-buffer object.
///
/// @details
///     - Prefetching may not be supported for all devices or allocation types.
///       If memory prefetching is not supported, the prefetch hint will be
///       ignored.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMemory`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_MIGRATION_FLAGS_MASK & flags`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pMemory`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendUSMPrefetchExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,  ///< [in] handle of the command-buffer object.
    const void *pMemory, ///< [in] pointer to USM allocated memory to prefetch.
    size_t size,         ///< [in] size in bytes to be fetched.
    ur_usm_migration_flags_t flags, ///< [in] USM prefetch flags
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Append a USM Advise command to a command-buffer object.
///
/// @details
///     - Not all memory advice hints may be supported for all devices or
///       allocation types. If a memory advice hint is not supported, it will be
///       ignored.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMemory`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_USM_ADVICE_FLAGS_MASK & advice`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_EXP
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_SYNC_POINT_WAIT_LIST_EXP
///         + `pSyncPointWaitList == NULL && numSyncPointsInWaitList > 0`
///         + `pSyncPointWaitList != NULL && numSyncPointsInWaitList == 0`
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `size == 0`
///         + If `size` is higher than the allocation size of `pMemory`
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If the device associated with `hCommandBuffer` does not support UR_DEVICE_INFO_COMMAND_BUFFER_EVENT_SUPPORT_EXP and either `phEvent` or `phEventWaitList` are not NULL.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferAppendUSMAdviseExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer,           ///< [in] handle of the command-buffer object.
    const void *pMemory,          ///< [in] pointer to the USM memory object.
    size_t size,                  ///< [in] size in bytes to be advised.
    ur_usm_advice_flags_t advice, ///< [in] USM memory advice
    uint32_t
        numSyncPointsInWaitList, ///< [in] The number of sync points in the provided dependency list.
    const ur_exp_command_buffer_sync_point_t *
        pSyncPointWaitList, ///< [in][optional] A list of sync points that this command depends on. May
                            ///< be ignored if command-buffer is in-order.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
    ur_exp_command_buffer_sync_point_t *
        pSyncPoint, ///< [out][optional] sync point associated with this command.
    ur_event_handle_t *
        phEvent, ///< [out][optional] return an event object that will be signaled by the
                 ///< completion of this command in the next execution of the
                 ///< command-buffer.
    ur_exp_command_buffer_command_handle_t
        *phCommand ///< [out][optional] Handle to this command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Submit a command-buffer for execution on a queue.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferEnqueueExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer, ///< [in] Handle of the command-buffer object.
    ur_queue_handle_t
        hQueue, ///< [in] The queue to submit this command-buffer for execution.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command-buffer execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating no wait events.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command-buffer execution instance. If phEventWaitList and phEvent are
    ///< not NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Increment the command object's reference count.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferRetainCommandExp(
    ur_exp_command_buffer_command_handle_t
        hCommand ///< [in][retain] Handle of the command-buffer command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Decrement the command object's reference count and delete the command
///        object if the reference count becomes zero.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferReleaseCommandExp(
    ur_exp_command_buffer_command_handle_t
        hCommand ///< [in][release] Handle of the command-buffer command.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Update a kernel launch command in a finalized command-buffer.
///
/// @details
/// This entry-point is synchronous and may block if the command-buffer is executing when the entry-point is called.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pUpdateKernelLaunch`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If update functionality is not supported by the device.
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If ::ur_exp_command_buffer_desc_t::isUpdatable was not set to true on creation of the command buffer `hCommand` belongs to.
///         + If the command-buffer `hCommand` belongs to has not been finalized.
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP - "If `hCommand` is not a kernel execution command."
///     - ::UR_RESULT_ERROR_INVALID_MEM_OBJECT
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_INDEX
///     - ::UR_RESULT_ERROR_INVALID_KERNEL_ARGUMENT_SIZE
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///     - ::UR_RESULT_ERROR_INVALID_WORK_DIMENSION
///         + `pUpdateKernelLaunch->newWorkDim < 1 || pUpdateKernelLaunch->newWorkDim > 3`
///     - ::UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///         + If `pUpdateKernelLaunch->hNewKernel` was not passed to the `hKernel` or `phKernelAlternatives` parameters of ::urCommandBufferAppendKernelLaunchExp when this command was created.
///         + If `pUpdateKernelLaunch->newWorkDim` is different from the current workDim in `hCommand` and, pUpdateKernelLaunch->pNewGlobalWorkSize, or pUpdateKernelLaunch->pNewGlobalWorkOffset are nullptr.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferUpdateKernelLaunchExp(
    ur_exp_command_buffer_command_handle_t
        hCommand, ///< [in] Handle of the command-buffer kernel command to update.
    const ur_exp_command_buffer_update_kernel_launch_desc_t *
        pUpdateKernelLaunch ///< [in] Struct defining how the kernel command is to be updated.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get a new event that will be signaled the next time the command in the
///        command-buffer executes.
///
/// @details
/// It is the users responsibility to release the returned `phSignalEvent`.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phSignalEvent`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If UR_DEVICE_COMMAND_BUFFER_UPDATE_CAPABILITY_FLAG_EVENTS is not supported by the device associated with `hCommand`.
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If ::ur_exp_command_buffer_desc_t::isUpdatable was not set to true on creation of the command buffer `hCommand` belongs to.
///         + If the command-buffer `hCommand` belongs to has not been finalized.
///         + If no `phEvent` parameter was set on creation of the command associated with `hCommand`.
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferUpdateSignalEventExp(
    ur_exp_command_buffer_command_handle_t
        hCommand, ///< [in] Handle of the command-buffer command to update.
    ur_event_handle_t *phSignalEvent ///< [out] Event to be signaled.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set the list of wait events for a command to depend on to a list of
///        new events.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_FEATURE
///         + If UR_DEVICE_COMMAND_BUFFER_UPDATE_CAPABILITY_FLAG_EVENTS is not supported by the device associated with `hCommand`.
///     - ::UR_RESULT_ERROR_INVALID_OPERATION
///         + If ::ur_exp_command_buffer_desc_t::isUpdatable was not set to true on creation of the command buffer `hCommand` belongs to.
///         + If the command-buffer `hCommand` belongs to has not been finalized.
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///         + If `numEventsInWaitList` does not match the number of wait events set when the command associated with `hCommand` was created.
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urCommandBufferUpdateWaitEventsExp(
    ur_exp_command_buffer_command_handle_t
        hCommand, ///< [in] Handle of the command-buffer command to update.
    uint32_t numEventsInWaitList, ///< [in] Size of the event wait list.
    const ur_event_handle_t *
        phEventWaitList ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the command execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating no wait events.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get command-buffer object information.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommandBuffer`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_COMMAND_BUFFER_INFO_DESCRIPTOR < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferGetInfoExp(
    ur_exp_command_buffer_handle_t
        hCommandBuffer, ///< [in] handle of the command-buffer object
    ur_exp_command_buffer_info_t
        propName, ///< [in] the name of the command-buffer property to query
    size_t
        propSize, ///< [in] size in bytes of the command-buffer property value
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the
                    ///< command-buffer property
    size_t *
        pPropSizeRet ///< [out][optional] bytes returned in command-buffer property
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get command-buffer object information.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hCommand`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_COMMAND_BUFFER_COMMAND_INFO_REFERENCE_COUNT < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_ERROR_INVALID_COMMAND_BUFFER_COMMAND_HANDLE_EXP
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
ur_result_t UR_APICALL urCommandBufferCommandGetInfoExp(
    ur_exp_command_buffer_command_handle_t
        hCommand, ///< [in] handle of the command-buffer command object
    ur_exp_command_buffer_command_info_t
        propName, ///< [in] the name of the command-buffer command property to query
    size_t
        propSize, ///< [in] size in bytes of the command-buffer command property value
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] value of the
                    ///< command-buffer command property
    size_t *
        pPropSizeRet ///< [out][optional] bytes returned in command-buffer command property
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command to execute a cooperative kernel
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalWorkOffset`
///         + `NULL == pGlobalWorkSize`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_INVALID_WORK_DIMENSION
///     - ::UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueCooperativeKernelLaunchExp(
    ur_queue_handle_t hQueue,   ///< [in] handle of the queue object
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t
        workDim, ///< [in] number of dimensions, from 1 to 3, to specify the global and
                 ///< work-group work-items
    const size_t *
        pGlobalWorkOffset, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< offset used to calculate the global ID of a work-item
    const size_t *
        pGlobalWorkSize, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< number of global work-items in workDim that will execute the kernel
    ///< function
    const size_t *
        pLocalWorkSize, ///< [in][optional] pointer to an array of workDim unsigned values that
    ///< specify the number of local work-items forming a work-group that will
    ///< execute the kernel function.
    ///< If nullptr, the runtime implementation will choose the work-group size.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Query the maximum number of work groups for a cooperative kernel
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hKernel`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pLocalWorkSize`
///         + `NULL == pGroupCountRet`
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
ur_result_t UR_APICALL urKernelSuggestMaxCooperativeGroupCountExp(
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t
        workDim, ///< [in] number of dimensions, from 1 to 3, to specify the work-group
                 ///< work-items
    const size_t *
        pLocalWorkSize, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< number of local work-items forming a work-group that will execute the
    ///< kernel function.
    size_t
        dynamicSharedMemorySize, ///< [in] size of dynamic shared memory, for each work-group, in bytes,
    ///< that will be used when the kernel is launched
    uint32_t *pGroupCountRet ///< [out] pointer to maximum number of groups
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a command for recording the device timestamp
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phEvent`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
ur_result_t UR_APICALL urEnqueueTimestampRecordingExp(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    bool
        blocking, ///< [in] indicates whether the call to this function should block until
    ///< until the device timestamp recording command has executed on the
    ///< device.
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating no wait events.
    ur_event_handle_t *
        phEvent ///< [in,out] return an event object that identifies this particular kernel
                ///< execution instance. Profiling information can be queried
    ///< from this event as if `hQueue` had profiling enabled. Querying
    ///< `UR_PROFILING_INFO_COMMAND_QUEUED` or `UR_PROFILING_INFO_COMMAND_SUBMIT`
    ///< reports the timestamp at the time of the call to this function.
    ///< Querying `UR_PROFILING_INFO_COMMAND_START` or `UR_PROFILING_INFO_COMMAND_END`
    ///< reports the timestamp recorded when the command is executed on the
    ///< device. If phEventWaitList and phEvent are not NULL, phEvent must not
    ///< refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Launch kernel with custom launch properties
///
/// @details
///     - Launches the kernel using the specified launch properties
///     - If numPropsInLaunchPropList == 0 then a regular kernel launch is used:
///       `urEnqueueKernelLaunch`
///     - Consult the appropriate adapter driver documentation for details of
///       adapter specific behavior and native error codes that may be returned.
///
/// @remarks
///   _Analogues_
///     - **cuLaunchKernelEx**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///         + `NULL == hKernel`
///         + NULL == hQueue
///         + NULL == hKernel
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pGlobalWorkOffset`
///         + `NULL == pGlobalWorkSize`
///         + `NULL == launchPropList`
///         + NULL == pGlobalWorkSize
///         + numPropsInLaunchpropList != 0 && launchPropList == NULL
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_KERNEL
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + phEventWaitList == NULL && numEventsInWaitList > 0
///         + phEventWaitList != NULL && numEventsInWaitList == 0
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in phEventWaitList has ::UR_EVENT_STATUS_ERROR
///     - ::UR_RESULT_ERROR_INVALID_WORK_DIMENSION
///     - ::UR_RESULT_ERROR_INVALID_WORK_GROUP_SIZE
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueKernelLaunchCustomExp(
    ur_queue_handle_t hQueue,   ///< [in] handle of the queue object
    ur_kernel_handle_t hKernel, ///< [in] handle of the kernel object
    uint32_t
        workDim, ///< [in] number of dimensions, from 1 to 3, to specify the global and
                 ///< work-group work-items
    const size_t *
        pGlobalWorkOffset, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< offset used to calculate the global ID of a work-item
    const size_t *
        pGlobalWorkSize, ///< [in] pointer to an array of workDim unsigned values that specify the
    ///< number of global work-items in workDim that will execute the kernel
    ///< function
    const size_t *
        pLocalWorkSize, ///< [in][optional] pointer to an array of workDim unsigned values that
    ///< specify the number of local work-items forming a work-group that will
    ///< execute the kernel function. If nullptr, the runtime implementation
    ///< will choose the work-group size.
    uint32_t numPropsInLaunchPropList, ///< [in] size of the launch prop list
    const ur_exp_launch_property_t *
        launchPropList, ///< [in][range(0, numPropsInLaunchPropList)] pointer to a list of launch
                        ///< properties
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution. If nullptr,
    ///< the numEventsInWaitList must be 0, indicating that no wait event.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< kernel execution instance. If phEventWaitList and phEvent are not
    ///< NULL, phEvent must not refer to an element of the phEventWaitList
    ///< array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one program, negates need for the
///        linking step.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point, the program passed
///       will contain a binary of the ::UR_PROGRAM_BINARY_TYPE_EXECUTABLE type
///       for each device in `phDevices`.
///
/// @remarks
///   _Analogues_
///     - **clBuildProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevices`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If `hProgram` isn't a valid program object.
///     - ::UR_RESULT_ERROR_PROGRAM_BUILD_FAILURE
///         + If an error occurred when building `hProgram`.
ur_result_t UR_APICALL urProgramBuildExp(
    ur_program_handle_t hProgram, ///< [in] Handle of the program to build.
    uint32_t numDevices,          ///< [in] number of devices
    ur_device_handle_t *
        phDevices, ///< [in][range(0, numDevices)] pointer to array of device handles
    const char *
        pOptions ///< [in][optional] pointer to build options null-terminated string.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one or more programs.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point `hProgram` will
///       contain a binary of the ::UR_PROGRAM_BINARY_TYPE_COMPILED_OBJECT type
///       for each device in `phDevices`.
///
/// @remarks
///   _Analogues_
///     - **clCompileProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hProgram`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevices`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If `hProgram` isn't a valid program object.
///     - ::UR_RESULT_ERROR_PROGRAM_BUILD_FAILURE
///         + If an error occurred while compiling `hProgram`.
ur_result_t UR_APICALL urProgramCompileExp(
    ur_program_handle_t
        hProgram,        ///< [in][out] handle of the program to compile.
    uint32_t numDevices, ///< [in] number of devices
    ur_device_handle_t *
        phDevices, ///< [in][range(0, numDevices)] pointer to array of device handles
    const char *
        pOptions ///< [in][optional] pointer to build options null-terminated string.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Produces an executable program from one or more programs.
///
/// @details
///     - The application may call this function from simultaneous threads.
///     - Following a successful call to this entry point the program returned
///       in `phProgram` will contain a binary of the
///       ::UR_PROGRAM_BINARY_TYPE_EXECUTABLE type for each device in
///       `phDevices`.
///     - If a non-success code is returned and `phProgram` is not `nullptr`, it
///       will contain an unspecified program or `nullptr`. Implementations may
///       use the build log of this program (accessible via
///       ::urProgramGetBuildInfo) to provide an error log for the linking
///       failure.
///
/// @remarks
///   _Analogues_
///     - **clLinkProgram**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == phDevices`
///         + `NULL == phPrograms`
///         + `NULL == phProgram`
///     - ::UR_RESULT_ERROR_INVALID_PROGRAM
///         + If one of the programs in `phPrograms` isn't a valid program object.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `count == 0`
///     - ::UR_RESULT_ERROR_PROGRAM_LINK_FAILURE
///         + If an error occurred while linking `phPrograms`.
ur_result_t UR_APICALL urProgramLinkExp(
    ur_context_handle_t hContext, ///< [in] handle of the context instance.
    uint32_t numDevices,          ///< [in] number of devices
    ur_device_handle_t *
        phDevices, ///< [in][range(0, numDevices)] pointer to array of device handles
    uint32_t count, ///< [in] number of program handles in `phPrograms`.
    const ur_program_handle_t *
        phPrograms, ///< [in][range(0, count)] pointer to array of program handles.
    const char *
        pOptions, ///< [in][optional] pointer to linker options null-terminated string.
    ur_program_handle_t
        *phProgram ///< [out] pointer to handle of program object created.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Import memory into USM
///
/// @details
///     - Import memory into USM
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
///     - ::UR_RESULT_ERROR_INVALID_SIZE
ur_result_t UR_APICALL urUSMImportExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    void *pMem,                   ///< [in] pointer to host memory object
    size_t size ///< [in] size in bytes of the host memory object to be imported
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Release memory from USM
///
/// @details
///     - Release memory from USM
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hContext`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pMem`
///     - ::UR_RESULT_ERROR_INVALID_CONTEXT
ur_result_t UR_APICALL urUSMReleaseExp(
    ur_context_handle_t hContext, ///< [in] handle of the context object
    void *pMem                    ///< [in] pointer to host memory object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enable access to peer device memory
///
/// @details
///     - Enables the command device to access and write device memory
///       allocations located on the peer device, provided that a P2P link
///       between the two devices is available.
///     - When Peer Access is successfully enabled, P2P memory accesses are
///       guaranteed to be allowed on the peer device until
///       ::urUsmP2PDisablePeerAccessExp is called.
///     - Note that the function operands may, but aren't guaranteed to, commute
///       for a given adapter: the peer device is not guaranteed to have access
///       to device memory allocations located on the command device.
///     - It is not guaranteed that the commutation relations of the function
///       arguments are identical for peer access and peer copies: For example,
///       for a given adapter the peer device may be able to copy data from the
///       command device, but not access and write the same data on the command
///       device.
///     - Consult the appropriate adapter driver documentation for details of
///       adapter specific behavior and native error codes that may be returned.
///
/// @remarks
///   _Analogues_
///     - **cuCtxEnablePeerAccess**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == commandDevice`
///         + `NULL == peerDevice`
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
ur_result_t UR_APICALL urUsmP2PEnablePeerAccessExp(
    ur_device_handle_t
        commandDevice,            ///< [in] handle of the command device object
    ur_device_handle_t peerDevice ///< [in] handle of the peer device object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Disable access to peer device memory
///
/// @details
///     - Disables the ability of the command device to access and write device
///       memory allocations located on the peer device, provided that a P2P
///       link between the two devices was enabled prior to the call.
///     - Note that the function operands may, but aren't guaranteed to, commute
///       for a given adapter. If, prior to the function call, the peer device
///       had access to device memory allocations on the command device, it is
///       not guaranteed to still have such access following the function
///       return.
///     - It is not guaranteed that the commutation relations of the function
///       arguments are identical for peer access and peer copies: For example
///       for a given adapter, if, prior to the call, the peer device had access
///       to device memory allocations on the command device, the peer device
///       may still, following the function call, be able to copy data from the
///       command device, but not access and write the same data on the command
///       device.
///     - Consult the appropriate adapter driver documentation for details of
///       adapter specific behavior and native error codes that may be returned.
///
/// @remarks
///   _Analogues_
///     - **cuCtxDisablePeerAccess**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == commandDevice`
///         + `NULL == peerDevice`
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
ur_result_t UR_APICALL urUsmP2PDisablePeerAccessExp(
    ur_device_handle_t
        commandDevice,            ///< [in] handle of the command device object
    ur_device_handle_t peerDevice ///< [in] handle of the peer device object
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Disable access to peer device memory
///
/// @details
///     - Queries the peer access capabilities from the command device to the
///       peer device according to the query `propName`.
///
/// @remarks
///   _Analogues_
///     - **cuDeviceGetP2PAttribute**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == commandDevice`
///         + `NULL == peerDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_PEER_INFO_UR_PEER_ATOMICS_SUPPORTED < propName`
///     - ::UR_RESULT_ERROR_UNSUPPORTED_ENUMERATION
///         + If `propName` is not supported by the adapter.
///     - ::UR_RESULT_ERROR_INVALID_SIZE
///         + `propSize == 0 && pPropValue != NULL`
///         + If `propSize` is less than the real number of bytes needed to return the info.
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `propSize != 0 && pPropValue == NULL`
///         + `pPropValue == NULL && pPropSizeRet == NULL`
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
ur_result_t UR_APICALL urUsmP2PPeerAccessGetInfoExp(
    ur_device_handle_t
        commandDevice,             ///< [in] handle of the command device object
    ur_device_handle_t peerDevice, ///< [in] handle of the peer device object
    ur_exp_peer_info_t propName,   ///< [in] type of the info to retrieve
    size_t propSize, ///< [in] the number of bytes pointed to by pPropValue.
    void *
        pPropValue, ///< [out][optional][typename(propName, propSize)] array of bytes holding
                    ///< the info.
    ///< If propSize is not equal to or greater than the real number of bytes
    ///< needed to return the info
    ///< then the ::UR_RESULT_ERROR_INVALID_SIZE error is returned and
    ///< pPropValue is not used.
    size_t *
        pPropSizeRet ///< [out][optional] pointer to the actual size in bytes of the queried propName.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Enqueue a barrier command which waits a list of events to complete
///        before it completes, with optional extended properties
///
/// @details
///     - If the event list is empty, it waits for all previously enqueued
///       commands to complete.
///     - It blocks command execution - any following commands enqueued after it
///       do not execute until it completes.
///     - It returns an event which can be waited on.
///
/// @remarks
///   _Analogues_
///     - **clEnqueueBarrierWithWaitList**
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_EXP_ENQUEUE_EXT_FLAGS_MASK & pProperties->flags`
///     - ::UR_RESULT_ERROR_INVALID_QUEUE
///     - ::UR_RESULT_ERROR_INVALID_EVENT
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
///         + `phEventWaitList == NULL && numEventsInWaitList > 0`
///         + `phEventWaitList != NULL && numEventsInWaitList == 0`
///         + If event objects in phEventWaitList are not valid events.
///     - ::UR_RESULT_ERROR_IN_EVENT_LIST_EXEC_STATUS
///         + An event in `phEventWaitList` has ::UR_EVENT_STATUS_ERROR.
///     - ::UR_RESULT_ERROR_INVALID_VALUE
///     - ::UR_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::UR_RESULT_ERROR_OUT_OF_RESOURCES
ur_result_t UR_APICALL urEnqueueEventsWaitWithBarrierExt(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    const ur_exp_enqueue_ext_properties_t *
        pProperties, ///< [in][optional] pointer to the extended enqueue properties
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before this command can be executed.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating that all
    ///< previously enqueued commands
    ///< must be complete.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies this particular
    ///< command instance. If phEventWaitList and phEvent are not NULL, phEvent
    ///< must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Immediately enqueue work through a native backend API
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hQueue`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == pfnNativeEnqueue`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `NULL != pProperties && ::UR_EXP_ENQUEUE_NATIVE_COMMAND_FLAGS_MASK & pProperties->flags`
///     - ::UR_RESULT_ERROR_INVALID_EVENT_WAIT_LIST
ur_result_t UR_APICALL urEnqueueNativeCommandExp(
    ur_queue_handle_t hQueue, ///< [in] handle of the queue object
    ur_exp_enqueue_native_command_function_t
        pfnNativeEnqueue, ///< [in] function calling the native underlying API, to be executed
                          ///< immediately.
    void *data,                ///< [in][optional] data used by pfnNativeEnqueue
    uint32_t numMemsInMemList, ///< [in] size of the mem list
    const ur_mem_handle_t *
        phMemList, ///< [in][optional][range(0, numMemsInMemList)] mems that are used within
                   ///< pfnNativeEnqueue using ::urMemGetNativeHandle.
    ///< If nullptr, the numMemsInMemList must be 0, indicating that no mems
    ///< are accessed with ::urMemGetNativeHandle within pfnNativeEnqueue.
    const ur_exp_enqueue_native_command_properties_t *
        pProperties, ///< [in][optional] pointer to the native enqueue properties
    uint32_t numEventsInWaitList, ///< [in] size of the event wait list
    const ur_event_handle_t *
        phEventWaitList, ///< [in][optional][range(0, numEventsInWaitList)] pointer to a list of
    ///< events that must be complete before the kernel execution.
    ///< If nullptr, the numEventsInWaitList must be 0, indicating no wait events.
    ur_event_handle_t *
        phEvent ///< [out][optional] return an event object that identifies the work that has
    ///< been enqueued in nativeEnqueueFunc. If phEventWaitList and phEvent are
    ///< not NULL, phEvent must not refer to an element of the phEventWaitList array.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Encode tensor map with image data
///
/// @details
///     - Map encode using im2col.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_TENSOR_MAP_DATA_TYPE_FLAGS_MASK & TensorMapType`
///         + `::UR_EXP_TENSOR_MAP_INTERLEAVE_FLAGS_MASK & Interleave`
///         + `::UR_EXP_TENSOR_MAP_SWIZZLE_FLAGS_MASK & Swizzle`
///         + `::UR_EXP_TENSOR_MAP_L2_PROMOTION_FLAGS_MASK & L2Promotion`
///         + `::UR_EXP_TENSOR_MAP_OOB_FILL_FLAGS_MASK & OobFill`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == GlobalAddress`
///         + `NULL == GlobalDim`
///         + `NULL == GlobalStrides`
///         + `NULL == PixelBoxLowerCorner`
///         + `NULL == PixelBoxUpperCorner`
///         + `NULL == ElementStrides`
///         + `NULL == hTensorMap`
///     - ::UR_RESULT_ERROR_INVALID_ARGUMENT
///         + `TensorRank < 3`
ur_result_t UR_APICALL urTensorMapEncodeIm2ColExp(
    ur_device_handle_t hDevice, ///< [in] Handle of the device object.
    ur_exp_tensor_map_data_type_flags_t
        TensorMapType,   ///< [in] Data type of the tensor object.
    uint32_t TensorRank, ///< [in] Dimensionality of tensor; must be at least 3.
    void *
        GlobalAddress, ///< [in] Starting address of memory region described by tensor.
    const uint64_t *
        GlobalDim, ///< [in] Array containing tensor size (number of elements) along each of
                   ///< the TensorRank dimensions.
    const uint64_t *
        GlobalStrides, ///< [in] Array containing stride size (in bytes) along each of the
                       ///< TensorRank - 1 dimensions.
    const int *
        PixelBoxLowerCorner, ///< [in] Array containing DHW dimensions of lower box corner.
    const int *
        PixelBoxUpperCorner, ///< [in] Array containing DHW dimensions of upper box corner.
    uint32_t ChannelsPerPixel, ///< [in] Number of channels per pixel.
    uint32_t PixelsPerColumn,  ///< [in] Number of pixels per column.
    const uint32_t *
        ElementStrides, ///< [in] Array containing traversal stride in each of the TensorRank
                        ///< dimensions.
    ur_exp_tensor_map_interleave_flags_t
        Interleave, ///< [in] Type of interleaved layout the tensor addresses
    ur_exp_tensor_map_swizzle_flags_t
        Swizzle, ///< [in] Bank swizzling pattern inside shared memory
    ur_exp_tensor_map_l2_promotion_flags_t
        L2Promotion, ///< [in] L2 promotion size.
    ur_exp_tensor_map_oob_fill_flags_t
        OobFill, ///< [in] Indicates whether zero or special NaN constant will be used to
                 ///< fill out-of-bounds elements.
    ur_exp_tensor_map_handle_t
        *hTensorMap ///< [out] Handle of the tensor map object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Encode tensor map with tiled data
///
/// @details
///     - Tiled map encode.
///
/// @returns
///     - ::UR_RESULT_SUCCESS
///     - ::UR_RESULT_ERROR_UNINITIALIZED
///     - ::UR_RESULT_ERROR_DEVICE_LOST
///     - ::UR_RESULT_ERROR_ADAPTER_SPECIFIC
///     - ::UR_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `NULL == hDevice`
///     - ::UR_RESULT_ERROR_INVALID_ENUMERATION
///         + `::UR_EXP_TENSOR_MAP_DATA_TYPE_FLAGS_MASK & TensorMapType`
///         + `::UR_EXP_TENSOR_MAP_INTERLEAVE_FLAGS_MASK & Interleave`
///         + `::UR_EXP_TENSOR_MAP_SWIZZLE_FLAGS_MASK & Swizzle`
///         + `::UR_EXP_TENSOR_MAP_L2_PROMOTION_FLAGS_MASK & L2Promotion`
///         + `::UR_EXP_TENSOR_MAP_OOB_FILL_FLAGS_MASK & OobFill`
///     - ::UR_RESULT_ERROR_INVALID_NULL_POINTER
///         + `NULL == GlobalAddress`
///         + `NULL == GlobalDim`
///         + `NULL == GlobalStrides`
///         + `NULL == BoxDim`
///         + `NULL == ElementStrides`
///         + `NULL == hTensorMap`
///     - ::UR_RESULT_ERROR_INVALID_ARGUMENT
///         + `TensorRank < 3`
ur_result_t UR_APICALL urTensorMapEncodeTiledExp(
    ur_device_handle_t hDevice, ///< [in] Handle of the device object.
    ur_exp_tensor_map_data_type_flags_t
        TensorMapType,   ///< [in] Data type of the tensor object.
    uint32_t TensorRank, ///< [in] Dimensionality of tensor; must be at least 3.
    void *
        GlobalAddress, ///< [in] Starting address of memory region described by tensor.
    const uint64_t *
        GlobalDim, ///< [in] Array containing tensor size (number of elements) along each of
                   ///< the TensorRank dimensions.
    const uint64_t *
        GlobalStrides, ///< [in] Array containing stride size (in bytes) along each of the
                       ///< TensorRank - 1 dimensions.
    const uint32_t *
        BoxDim, ///< [in] Array containing traversal box size (number of elments) along
    ///< each of the TensorRank dimensions. Specifies how many elements to be
    ///< traversed along each tensor dimension.
    const uint32_t *
        ElementStrides, ///< [in] Array containing traversal stride in each of the TensorRank
                        ///< dimensions.
    ur_exp_tensor_map_interleave_flags_t
        Interleave, ///< [in] Type of interleaved layout the tensor addresses
    ur_exp_tensor_map_swizzle_flags_t
        Swizzle, ///< [in] Bank swizzling pattern inside shared memory
    ur_exp_tensor_map_l2_promotion_flags_t
        L2Promotion, ///< [in] L2 promotion size.
    ur_exp_tensor_map_oob_fill_flags_t
        OobFill, ///< [in] Indicates whether zero or special NaN constant will be used to
                 ///< fill out-of-bounds elements.
    ur_exp_tensor_map_handle_t
        *hTensorMap ///< [out] Handle of the tensor map object.
) {
    ur_result_t result = UR_RESULT_SUCCESS;
    return result;
}
