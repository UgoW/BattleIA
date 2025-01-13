
#ifndef BATTLE_C_H
#define BATTLE_C_H

#include "stdbool.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque structure representing a connection to the server.
 */
typedef struct BC_Connection_ {
} BC_Connection;

/**
 * @brief Opaque structure representing a linked list.
 */
typedef struct BC_List_ {
} BC_List;

/**
 * @brief Structure representing a 3D vector.
 */
typedef struct BC_Vector3_ {
  int x; ///< X-coordinate
  int y; ///< Y-coordinate
  int z; ///< Z-coordinate
} BC_Vector3;

/**
 * @brief Structure representing a 2D vector.
 */
typedef struct BC_Vector2_ {
  int x; ///< X-coordinate
  int y; ///< Y-coordinate
} BC_Vector2;

/**
 * @brief Enum representing the type of a map object.
 */
enum BC_ObjectType {
  OT_PLAYER, ///< Player object
  OT_WALL,   ///< Wall object
  OT_BOOST   ///< Boost object
};

/**
 * @brief Structure representing player data.
 */
typedef struct BC_PlayerData_ {
  int id;              ///< Player ID
  BC_Vector3 position; ///< Player's position in 3D space
  BC_Vector3 speed;    ///< Player's speed in 3D space
  int health;          ///< Player's health
} BC_PlayerData;

/**
 * @brief Structure representing boost object data.
 */
typedef struct BC_BoostObjectData_ {
  int health; ///< Health value of the boost object
} BC_BoostObjectData;

/**
 * @brief Structure representing a generic map object.
 */
typedef struct BC_MapObject_ {
  enum BC_ObjectType type; ///< Type of the object (player, wall, or boost)
  int id;                  ///< Unique object ID
  BC_Vector3 position;     ///< Position of the object in 3D space
  BC_Vector3 speed;        ///< Speed of the object in 3D space
  int health;              ///< Health of the object
} BC_MapObject;

/**
 * @brief Structure containing world information.
 */
typedef struct BC_WorldInfo_ {
  uint64_t map_x;          ///< Width of the map
  uint64_t map_y;          ///< Height of the map
  uint32_t player_count;   ///< Number of players in the world
  bool auto_shoot_enabled; ///< Indicates if auto-shoot is enabled
  bool radar_enabled;      ///< Indicates if radar is enabled
} BC_WorldInfo;

/**
 * @brief Establishes a connection to the server.
 *
 * @param address The server address as a null-terminated string.
 * @param port The server port.
 * @return A pointer to an opaque BC_Connection object, or NULL on failure.
 */
BC_Connection *bc_connect(const char *address, int port);

/**
 * @brief Retrieves information about the world.
 *
 * @param connection A pointer to a BC_Connection object.
 * @return A BC_WorldInfo structure containing world details.
 */
BC_WorldInfo bc_get_world_info(BC_Connection *connection);

/**
 * @brief Disconnects from the server and frees resources.
 *
 * @param connection A pointer to a BC_Connection object to be disconnected.
 */
void bc_disconnect(BC_Connection *connection);

/**
 * @brief Retrieves data for the local player.
 *
 * @param connection A pointer to a BC_Connection object.
 * @return A BC_PlayerData structure containing player data.
 */
BC_PlayerData bc_get_player_data(BC_Connection *connection);

/**
 * @brief Sets the speed for the local player.
 *
 * @param connection A pointer to a BC_Connection object.
 * @param x The X component of the speed vector.
 * @param y The Y component of the speed vector.
 * @param z The Z component of the speed vector.
 */
void bc_set_speed(BC_Connection *connection, double x, double y, double z);

/**
 * @brief Sends a radar ping to detect nearby objects.
 *
 * @param connection A pointer to a BC_Connection object.
 * @return An opaque BC_List containing detected BC_MapObject objects.
 */
BC_List *bc_radar_ping(BC_Connection *connection);

/**
 * @brief Retrieves the next element in a linked list.
 *
 * @param bc_list A pointer to a BC_List object.
 * @return A pointer to the next BC_List object, or NULL if at the end.
 */
BC_List *bc_ll_next(BC_List *bc_list);

/**
 * @brief Retrieves the value of the current element in a linked list.
 *
 * @param bc_list A pointer to a BC_List object.
 * @return A void pointer to the value of the current element.
 */
void *bc_ll_value(BC_List *bc_list);

#ifdef __cplusplus
}
#endif

#endif // BATTLE_C_H
