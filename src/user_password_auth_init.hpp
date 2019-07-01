/*
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#ifndef __USER_PASSWORD_AUTH_INIT_HPP__
#define __USER_PASSWORD_AUTH_INIT_HPP__

#include <geode/AuthInitialize.hpp>
#include <geode/Properties.hpp>
#include <geode/Cache.hpp>
#include <cstdint>

using apache::geode::client::AuthInitialize;
using apache::geode::client::Properties;

namespace geode_user_password_auth {

class UserPasswordAuthInit : public AuthInitialize {
 public:
  UserPasswordAuthInit() {}
  ~UserPasswordAuthInit() {}

   std::shared_ptr<apache::geode::client::Properties> getCredentials(
      const std::shared_ptr<apache::geode::client::Properties>& securityprops,
      const std::string& server) override;

  void close() override;
};
}  // namespace geode_user_password_auth
#endif  //__USER_PASSWORD_AUTH_INIT.HPP__
