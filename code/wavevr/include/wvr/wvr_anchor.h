// "WaveVR SDK
// © 2022 HTC Corporation. All Rights Reserved.
//
// Unless otherwise required by copyright law and practice,
// upon the execution of HTC SDK license agreement,
// HTC grants you access to and use of the WaveVR SDK(s).
// You shall fully comply with all of HTC’s SDK license agreement terms and
// conditions signed by you and all SDK and API requirements,
// specifications, and documentation provided by HTC to You."

#ifndef wvr_anchor_h_
#define wvr_anchor_h_

#include "wvr_stdinc.h"
#include "wvr_types.h"

#include "begin_code.h"
#ifdef __cplusplus
extern "C" {
#endif

#define WVR_MAX_SPATIAL_ANCHOR_NAME_SIZE 256                 /**< maximum size for anchor's name */
#define WVR_DEFINE_HANDLE(object) typedef uint64_t object;

/**
 * @brief an object that allows an application to communicate with runtime
 */
WVR_DEFINE_HANDLE(WVR_SpatialAnchor)   /**< an object that allows an application to communicate with runtime */

/**
 * @brief name is a null terminated character array of size WVR_MAX_SPATIAL_ANCHOR_NAME_SIZE
 */
typedef struct WVR_SpatialAnchorName {
    char    name[WVR_MAX_SPATIAL_ANCHOR_NAME_SIZE];   /**< The name of the anchor */
} WVR_SpatialAnchorName;

/**
 * @brief The parameters to create a new spatial anchor used in @ref WVR_CreateSpatialAnchor API.
 *
 * Developers provide information to create an anchor, including pose, originModel and anchorName.
 * Note that only WVR_PoseOriginModel_OriginOnHead and WVR_PoseOriginModel_OriginOnGround cases are supported in originModel.
 */
typedef struct WVR_SpatialAnchorCreateInfo {
    WVR_Pose_t                  pose;           /**< The pose is an @ref WVR_Pose_t defining the position and orientation of the anchor. */
    WVR_PoseOriginModel         originModel;    /**< The pose's origin model, refer to @ref WVR_PoseOriginModel*/
    WVR_SpatialAnchorName       anchorName;     /**< The name of the anchor. */
} WVR_SpatialAnchorCreateInfo;

/**
 * @brief Function is used to create a spatial anchor.
 *
 * Developers use this API to create a spatial anchor and get an anchor handle.
 *
 * @param createInfo creation information, refer to @ref WVR_SpatialAnchorCreateInfo
 * @param anchor returned handle object that holds the spatial anchor is related to createInfo
 * @retval WVR_Success Create a spatial anchor successfully.
 * @retval others @ref WVR_Result mean failure.
 * @version API Level 11
 */
extern WVR_EXPORT WVR_Result WVR_CreateSpatialAnchor(
    const WVR_SpatialAnchorCreateInfo*      createInfo,
    WVR_SpatialAnchor*                      anchor);

/**
 * @brief Function is used to destroy a spatial anchor.
 *
 * Developers use this API to destroy an anchor handle.
 *
 * @param anchor the spatial anchor that developers would like to destroy
 * @retval WVR_Success Destroy a spatial anchor successfully.
 * @retval others @ref WVR_Result mean failure.
 * @version API Level 11
 */
extern WVR_EXPORT WVR_Result WVR_DestroySpatialAnchor(
    WVR_SpatialAnchor           anchor);

/**
 * @brief Function is used to enumerate anchors.
 *
 * This is two calls API. Developers should call this API with the value of anchorCapacityInput equals to 0 to retrieve
 * the size of anchors from anchorCountOutput. Then developers allocate the array of @ref WVR_SpatialAnchor handles and
 * assign the anchorCapacityInput and call the API in the second time. Then runtime will fill the handle anchors array.
 *
 * @param anchorCapacityInput the capacity of the anchor array, or 0 to indicate a request to retrieve the required capacity.
 * @param anchorCountOutput a pointer to the count of anchors written, or a pointer to the required capacity in the case that anchorCapacityInput is insufficient.
 * @param anchors a pointer to an array of @ref WVR_SpatialAnchor handles, but can be NULL if anchorCapacityInput is 0.
 * @retval WVR_Success Enumerate spatial anchors successfully.
 * @retval others @ref WVR_Result mean failure.
 * @version API Level 11
 */
extern WVR_EXPORT WVR_Result WVR_EnumerateSpatialAnchors(
    uint32_t                    anchorCapacityInput,
    uint32_t*                   anchorCountOutput,
    WVR_SpatialAnchor*          anchors);

/**
 * @brief enumerate different spatial anchor tracking state
 */
typedef enum {
    WVR_SpatialAnchorTrackingState_Tracking,       /**< Tracking state */
    WVR_SpatialAnchorTrackingState_Paused,         /**< Paused state */
    WVR_SpatialAnchorTrackingState_Stopped         /**< Stopped state */
} WVR_SpatialAnchorTrackingState;

/**
 * @brief returned anchor state
 */
typedef struct WVR_SpatialAnchorState {
    WVR_SpatialAnchorTrackingState      trackingState; /**< tracking state of the input anchor */
    WVR_Pose_t                          pose;          /**< the pose of anchor related to originModel */
    WVR_SpatialAnchorName               anchorName;    /**< The name of the anchor */
} WVR_SpatialAnchorState;

/**
 * @brief Function is used to retrieve @ref WVR_SpatialAnchorState related to the input anchor.
 *
 * @param anchor input anchor handle
 * @param originModel Only WVR_PoseOriginModel_OriginOnHead and WVR_PoseOriginModel_OriginOnGround are supported, refer to @ref WVR_PoseOriginModel.
 * @param anchorState the returned data related to input anchor
 * @retval WVR_Success Get the input spacial anchor state successfully.
 * @retval others @ref WVR_Result mean failure.
 * @version API Level 11
 */
extern WVR_EXPORT WVR_Result WVR_GetSpatialAnchorState(
    WVR_SpatialAnchor           anchor,
    WVR_PoseOriginModel         originModel,
    WVR_SpatialAnchorState*     anchorState);

#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* wvr_anchor_h_ */
